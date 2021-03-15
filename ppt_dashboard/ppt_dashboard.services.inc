<?php

/**
 * @file
 * Provide custom service resources.
 */

/**
 * Implements hook_resource().
 */
function ppt_dashboard_resource() {
  $api = array(
    'ppt_dashboard' => array(
  // Product reports.
      'actions' => array(
        'get_filters_values' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_dashboard',
            'name' => 'ppt_dashboard.services',
          ),
          'callback' => 'ppt_dashboard_get_filters_values',
          'args' => array(
                        array(
                          'name' => 'data',
                          'optional' => FALSE,
                          'source' => 'data',
                          'type' => 'array',
                          'description' => 'project to sort',
                        ),
          ),
          'access callback' => 'services_access_menu',
        ),
        'custom_login' => array(
          'help' => 'Login a user for a new session',
          'callback' => '_user_resource_custom_login',
          'args' => array(
            array(
              'name' => 'username',
              'type' => 'string',
              'description' => 'A valid username',
              'source' => array('data' => 'username'),
              'optional' => FALSE,
            ),
          ),
          'access callback' => 'services_access_menu',
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_dashboard',
            'name' => 'ppt_dashboard.services',
          ),
        ),        
      ),
    ),
  );

  return $api;
}

/**
 * Custom function.
 */
function ppt_dashboard_get_filters_values($data) {
  return ppt_dashboard_get_filters_arraies();
}

/**
 * Login a user using the specified credentials.
 *
 * Note this will transfer a plaintext password.
 *
 * @param $username
 *   Username to be logged in.
 * @param $password
 *   Password, must be plain text and not hashed.
 *
 * @return
 *   A valid session object.
 */
function _user_resource_custom_login($username) {
  global $user;

  if ($user->uid) {
    // user is already logged in
    return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 200);
  }

  // Check if account is active.
  if (user_is_blocked($username)) {
    return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
  }

  // Emulate drupal native flood control: check for flood condition.
  $flood_state = array();
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state = _user_resource_flood_control_precheck($username);
  }

  // Only authenticate if a flood condition was not detected.
  if (empty($flood_state['flood_control_triggered'])) {
    $uid = user_authenticate($username, $password);
  }
  else {
    $uid = FALSE;
  }

  // Emulate drupal native flood control: register flood event, and throw error
  // if a flood condition was previously detected
  if (variable_get('services_flood_control_enabled', TRUE)) {
    $flood_state['uid'] = $uid;
    _user_resource_flood_control_postcheck($flood_state);
  }

  if ($uid) {
    $user = user_load($uid);
    if ($user->uid) {
      user_login_finalize();

      $return = new stdClass();
      $return->sessid = session_id();
      $return->session_name = session_name();
      $return->token = drupal_get_token('services');

      $account = clone $user;

      services_remove_user_data($account);

      $return->user = $account;

      return $return;
    }
  }
  watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
  return services_error(t('Wrong username or password.'), 401);
}