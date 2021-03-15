<?php
// Call this at each point of interest, passing a descriptive string
function prof_flag($str)
{
  global $prof_timing, $prof_names;
  $prof_timing[] = microtime(true);
  $prof_names[] = $str;
}

// Call this when you're done and want to see the results
function prof_print()
{
  global $prof_timing, $prof_names;
  $size = count($prof_timing);
  for ($i = 0; $i < $size - 1; $i++) {
    echo "<b>{$prof_names[$i]}</b><br>";
    echo sprintf("&nbsp;&nbsp;&nbsp;%f<br>", $prof_timing[$i + 1] - $prof_timing[$i]);
  }
  echo "<b>{$prof_names[$size - 1]}</b><br>";
}
/**
 * @file
 * Services file.
 */

/**
 * Implements hook_resource().
 */
function ppt_resources_resource()
{
  $api = array(
    'ppt_resources' => array(
      // Product reports.
      'actions' => array(
        'get_products' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_products',
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
        'get_products_all' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_products_all',
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
        'get_indications' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_indications',
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
        'get_usd_stocks' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_usd_stocks',
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
        'get_target_account' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_target_account',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_target_total' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_target_total',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_planned_orders' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_planned_orders',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_user_clusters' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_user_clusters',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_user_countries_per_cluster' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_user_countries_per_cluster',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_accounts_per_countries' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_accounts_per_countries',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_accounts_products' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_accounts_products',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_target_accounts_products' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_target_accounts_products',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_reps_of_accounts_country' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_reps_of_accounts_country',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_accounts_indications' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_accounts_indications',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_indications_per_month' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_indications_per_month',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_consumptions_stocks_per_product' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_consumptions_stocks_per_product',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_planned_products_report' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_planned_products_report',
          'args' => array(
            array(
              'name' => 'data',
              'optional' => FALSE,
              'source' => 'data',
              'type' => 'array',
              'description' => 'project to sort',
            ),
          ),
          'access callback' => 'user_access',
          'access arguments' => array('access PPT dashboard reports'),
        ),
        'get_target_delivered_report' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_target_delivered_report',
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
        'get_next_planned_orders' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_next_planned_orders',
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
        'get_expected_orders' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'expected_orders',
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
        'get_planned_delivered' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_planned_delivered',
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
        'get_delivered_planned_orders' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_delivered_planned_orders',
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
        'get_team_accounts' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_team_accounts',
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
        'get_team_reps' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_team_reps',
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
        'get_team_account_reps' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_team_account_reps',
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
        'get_team_account_products' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'ppt_resources',
            'name' => 'ppt_resources.services',
          ),
          'callback' => 'ppt_resources_get_team_account_products',
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
      ),
    ),
  );

  return $api;
}

/**
 * REPORTS RESOURCES.
 */

/**
 * Per indication reports.
 */
function ppt_resources_get_indications($data)
{
  return ppt_resources_get($data, 'field_indication');
}

/**
 * Custom callback function.
 */
function ppt_resources_get_target_total($data)
{
  $report = ppt_resources_get_target_account($data);
  $final_report = array(
    'cot' => array(
      'Actual' => array(),
      'Target' => array(),
    ),
    'npr' => array(
      'Actual' => array(),
      'Target' => array(),
    ),
  );
  foreach ($report as $product_report) {
    foreach ($product_report as $report_name => $report) {
      foreach ($report as $line_name => $line_values) {
        foreach ($line_values as $month => $value) {
          if ($final_report[$report_name][$line_name][$month]) {
            $final_report[$report_name][$line_name][$month] += $value;
          } else {
            $final_report[$report_name][$line_name][$month] = $value;
          }
        }
      }
    }
  }
  return $final_report;
}

/**
 * Per product reports.
 */
function ppt_resources_get_products($data)
{
  return ppt_resources_get($data, 'field_product');
}

/**
 * Per product reports with parents.
 */
function ppt_resources_get_products_all($data)
{
  $report = ppt_resources_get_products($data);
  if (!isset($data['products']) || empty($data['products'])) {
    return $report;
  }

  foreach ($data['products'] as $productId) {
    $children = taxonomy_get_children($productId);
    if (!empty($children)) {
      // $dosage = taxonomy_term_load($productId);
      // $report[$dosage->name] = $report[$dosage->name];.
      $product = taxonomy_term_load($productId);
      $sumDosages = array();
      $childrenIds = array_keys($children);
      $newData = $data;
      $newData['products'] = $childrenIds;
      $oneProductReport = ppt_resources_get_products($newData);
      if (!empty($oneProductReport)) {
        foreach ($oneProductReport as $dosageReport) {
          foreach ($dosageReport as $monthName => $monthReport) {
            if (isset($sumDosages[$monthName])) {
              $sumDosages[$monthName][0] += $monthReport[0];
              $sumDosages[$monthName][1] += $monthReport[1];
              $sumDosages[$monthName][2] += $monthReport[2];
            } else {
              $sumDosages[$monthName] = $monthReport;
            }
          }
        }

        $report[$product->name] = $sumDosages;
      }
    }
  }
  return $report;
}

/**
 * Main resource function.
 */
function ppt_resources_get($data, $field_name)
{
  if (!user_is_logged_in()) {
    return services_error('Access denied', 403);
  }

  if (!isset($data['year'])) {
    return services_error('Year is not defined!', 500);
  }
  module_load_include('module', 'ppt_ta_access', 'ppt_ta_access');
  $year = $data['year'];
  // If there is no uid sent with the api so get the current user id.
  if (isset($data['uid'])) {
    $uid = $data['uid'];
  } else {
    global $user;
    $uid = $user->uid;
  }
  // Load user.
  $user = user_load($uid);

  $countries = array();
  if (isset($data['countries'])) {
    $countries = $data['countries'];
  }

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }
  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = $data['products'];
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid);
    } else {
      $products = get_products_for_accounts($accounts);
    }
  }

  $indications = [];
  // Check if user selected indications.
  if (isset($data['indications'])) {
    $indications = $data['indications'];
  } else {
    $indications = get_products_indications($products);
  }

  $reps = array();
  if (isset($data['reps'])) {
    $reps = $data['reps'];
  } else {
    $reps = ppt_resources_get_users_per_role($user, $countries);
  }

  $entries = get_entries($accounts, $products, $indications, $reps);
  $entries_records = get_entries_records_for_year($entries, $year, 'entry_month_record');
  $reports = sum_records_per_field($entries_records, $field_name);
  return $reports;
}

/**
 * Custom callback function.
 */
function ppt_resources_get_accounts_per_countries($data)
{
  $countries = array();
  if (isset($data['countries'])) {
    $countries = $data['countries'];
  }
  global $user;
  if (isset($data['uid'])) {
    $user = user_load($data['uid']);
  }
  $accounts_ids = ppt_resources_get_role_accounts($user, $countries);
  $accounts = node_load_multiple($accounts_ids);
  $accounts = array_map(function ($o) {
    $r = new stdClass();
    $r->id = $o->nid;
    $r->name = $o->title;
    return $r;
  }, $accounts);
  return $accounts;
}

/**
 * Get the accounts avaliable for each user depending on its role.
 */
function ppt_resources_get_role_accounts($user, $countries = array(), $only_valid_date = TRUE)
{
  if (!$user) {
    global $user;
  }

  $uid = $user->uid;
  if (!$countries || !isset($countries) || empty($countries)) {
    $countries = get_user_countries($user);
  }

  $accounts = array();

  // Check for current user.
  if (is_sales_manager($user)) {
    // If the user is sales manager we will get the reps under it.
    $reps = ppt_resources_get_sales_manager_reps($uid, $countries);
    // Get the accounts for each one of the reps.
    foreach ($reps as $rep) {
      $reps_accounts = get_accounts_for_current_user($rep->uid, FALSE);
      $accounts = array_merge($accounts, $reps_accounts);
    }
  } elseif (is_regional_lead($user)) {
    // Load all the sales manager for this regional lead and loop over them.
    $sales_managers = ppt_resources_get_regional_lead_sales_managers($uid);
    foreach ($sales_managers as $sales_manager) {
      $reps = ppt_resources_get_sales_manager_reps($sales_manager->uid, $countries);
      foreach ($reps as $rep) {
        $reps_accounts = get_accounts_for_current_user($rep->uid, FALSE);
        $accounts = array_merge($accounts, $reps_accounts);
      }
    }
  } elseif (is_comm_lead($user)) {
    $reps = ppt_resources_get_comm_lead_reps($user->uid);
    foreach ($reps as $rep) {
      $reps_accounts = get_accounts_for_current_user($rep->uid, FALSE);
      $accounts = array_merge($accounts, $reps_accounts);
    }
  } elseif (is_system_admin($user) || is_global_lead($user)) {

    foreach ($countries as $country) {
      $country_accounts = get_accounts_for_country($country);
      $accounts = array_merge($accounts, $country_accounts);
    }
  } elseif (is_data_admin($user)) {
    $reps = ppt_resources_get_data_admin_reps($user->uid);
    foreach ($reps as $rep) {
      $reps_accounts = get_accounts_for_current_user($rep->uid, FALSE);
      $accounts = array_merge($accounts, $reps_accounts);
    }
  } elseif (is_rep($user)) {
    $accounts = get_accounts_for_current_user($uid, $only_valid_date);
  }
  // Return array with removed dublication.
  return array_unique($accounts);
}

/**
 * Get the usd and stocks per account and product.
 */
function ppt_resources_get_usd_stocks($data)
{
//  return $data;
  if (!isset($data['year'])) {
    return services_error('Year is not defined!', 500);
  }

  $year = $data['year'];
  $accounts = [];
  // If there is no uid sent with the api so get the current user id.
  if (isset($data['uid'])) {
    $uid = $data['uid'];
  } else {
    global $user;
    $uid = $user->uid;
  }
  $countries = array();
  if (isset($data['countries'])) {
    $countries = $data['countries'];
  }
  $reps = array();
  if (isset($data['reps'])) {
    $reps = $data['reps'];
  }

  $user = user_load($uid);

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }

  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = get_products_dosages($data['products']);
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid);
    } else {
      $products = get_products_for_accounts($accounts);
    }
  }
//return entity_metadata_wrapper('field_collection_item', 18045);
  $entries = get_entries($accounts, $products, NULL, $reps);
  $entries_records = get_entries_records_for_year($entries, $year, 'consumption_stock_entry');
  $reports = sum_records_per_field($entries_records, 'field_product', TRUE);
  return $reports;
}

/**
 * Custom callback function.
 */
function get_products_dosages($products)
{
  $dosage_ids = [];
  foreach ($products as $dosageid) {
    $children = taxonomy_get_children($dosageid);
    if (!$children || empty($children)) {
      if (!in_array($dosageid, $dosage_ids)) {
        $dosage_ids[] = $dosageid;
      }
    } else {
      $dosage_ids = array_merge(array_keys($children), $dosage_ids);
    }
  }
  return $dosage_ids;
}

/**
 * Custom callback function.
 */
function ppt_resources_get_indications_per_month($data)
{
  if (isset($data['products'])) {
    $data['products'] = get_products_dosages($data['products']);
  }
  $report = ppt_resources_get_indications($data);
  $finalReport = array(
    "cot" => array(
      'Indication' => 'COT',
    ), "npr" => array(
      'Indication' => 'NPR',
    ),
  );

  // Return $report;.
  if (isset($data['month'])) {
    $month = $data['month'][0];
    foreach ($report as $indicationName => $indicationReport) {
      $totalCot = 0;
      $totalNpr = 0;
      foreach ($indicationReport as $monthName => $record) {
        $dateObj = DateTime::createFromFormat('!m', (int) $month);
        // March.
        $requriedMonthName = $dateObj->format('F');
        if ($requriedMonthName == $monthName) {
          $totalCot += $record[0];
          $totalNpr += $record[1];
        }
      }
      $finalReport["cot"][$indicationName] = $totalCot;
      $finalReport["npr"][$indicationName] = $totalNpr;
    }
    return $finalReport;
  }

  foreach ($report as $indicationName => $indicationReport) {
    $totalCot = 0;
    $totalNpr = 0;
    foreach ($indicationReport as $monthName => $record) {
      $totalCot += $record[0];
      $totalNpr += $record[1];
    }
    $finalReport["cot"][$indicationName] = $totalCot;
    $finalReport["npr"][$indicationName] = $totalNpr;
  }

  return $finalReport;
}

/**
 * Getting accounts in a country.
 */
function get_accounts_for_country($county_ids)
{
  if (!is_array($county_ids)) {
    $county_ids = array($county_ids);
  }
  // watchdog('test', json_encode(var_dump($county_ids)));
  $nodes = array();
  if (!empty($county_ids)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'account')
      ->fieldCondition('field_single_country', 'target_id', $county_ids, 'IN')
      ->addMetaData('account', user_load(1));

    $nodes = $query->execute();
  }

  // watchdog('test', json_encode($nodes));
  if (empty($nodes)) {
    return [];
  }

  // Extract ids from the nodes.
  $accounts = array_keys($nodes['node']);
  return $accounts;
}

/**
 * Getting accounts for current date only for current user.
 */
function get_accounts_for_current_user($uid, $only_valid_date = TRUE)
{

  // Load current user.
  $loaded_user = user_load($uid);

  // Getting the wrapper to easy extract data.
  $loaded_user_wrapper = entity_metadata_wrapper('user', $loaded_user);

  // Getting all the field collection items.
  $account_product_date_items = $loaded_user_wrapper->field_account_product_date->value();

  // Looping on each item to get the accounts.
  $accounts = [];
  foreach ($account_product_date_items as $item) {

    $item_wrapper = entity_metadata_wrapper('field_collection_item', $item);
    $account = $item_wrapper->field_account->value();

    // Check if the date is valid.
    $now = REQUEST_TIME;
    if ($item_wrapper->field_end_date->value()) {
      $date_valid = $now >= $item_wrapper->field_start_date->value() && $now <= $item_wrapper->field_end_date->value();
    } else {
      $date_valid = $now >= $item_wrapper->field_start_date->value();
    }

    // If the account isn't already in accounts array and the date still valid.
    if ($account && isset($account->nid) && !in_array($account->nid, $accounts)) {
      if (!$only_valid_date || $date_valid) {
        array_push($accounts, $account->nid);
      }
    }
  }

  return $accounts;
}

/**
 * Getting a list of products for each account.
 */
function get_products_for_accounts($accounts)
{
  module_load_include('module', 'ppt_ta_access', 'ppt_ta_access');
  // Looping over each account and load it.
  $products = [];
  if (empty($accounts)) {
    return $products;
  }
  foreach ($accounts as $account) {

    $account_wrapper = entity_metadata_wrapper('node', node_load($account));
    $account_products = $account_wrapper->field_products->value();

    // Loop over products, add the product if it isn't already in array.
    foreach ($account_products as $account_product) {
      if ($account_product) {
        if (!in_array($account_product->tid, $products) && ppt_ta_term_access($account_product)) {
          array_push($products, $account_product->tid);
        }
      }
    }
  }

  return $products;
}

/**
 * Getting a list of products for each account.
 */
function get_target_products_for_accounts($accounts)
{
  module_load_include('module', 'ppt_ta_access', 'ppt_ta_access');
  // Looping over each account and load it.
  $products = [];
  if (empty($accounts)) {
    return $products;
  }
  foreach ($accounts as $account) {

    $account_wrapper = entity_metadata_wrapper('node', node_load($account));
    $account_products = $account_wrapper->field_products->value();

    // Loop over products and add the product if it isn't already in array.
    foreach ($account_products as $account_product) {
      if ($account_product) {
        $parents = taxonomy_get_parents($account_product->tid);
        foreach ($parents as $parent) {
          if (!in_array($parent->tid, $products) && ppt_ta_term_access($parent)) {
            array_push($products, $parent->tid);
          }
        }
      }
    }
  }

  return $products;
}

/**
 * Getting products for current date only for current user.
 */
function get_products_for_current_user($uid, $dosages = FALSE, $only_valid_date = TRUE)
{

  // Load current user.
  $loaded_user = user_load($uid);

  // Getting the wrapper to easy extract data.
  $loaded_user_wrapper = entity_metadata_wrapper('user', $loaded_user);

  // Getting all the field collection items.
  $account_product_date_items = $loaded_user_wrapper->field_account_product_date->value();

  // Looping on each item to get the products.
  $products = [];
  foreach ($account_product_date_items as $item) {

    $item_wrapper = entity_metadata_wrapper('field_collection_item', $item);
    $account_products = $item_wrapper->field_product->value();

    // Check if the date is valid.
    $now = REQUEST_TIME;
    if ($item_wrapper->field_end_date->value()) {
      $date_valid = $now >= $item_wrapper->field_start_date->value() && $now <= $item_wrapper->field_end_date->value();
    } else {
      $date_valid = $now >= $item_wrapper->field_start_date->value();
    }

    if (!empty($account_products)) {
      // If the account isn't already in products and the date still valid.
      foreach ($account_products as $product) {
        if (($date_valid || !$only_valid_date) && !in_array($product->tid, $products)) {
          if ($dosages) {
            $children_tids = array_keys(taxonomy_get_children($product->tid));
            $products[$product->tid] = $children_tids;
          } else {
            array_push($products, $product->tid);
          }
        }
      }
    }
  }
  return $products;
}

/**
 * Getting the products indications array.
 */
function get_products_indications($products)
{
  $indications = [];
  // Loop over all products, store the indication if not found in array.
  foreach ($products as $product) {
    if ($product) {
      $term = taxonomy_term_load($product);
      $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);

      $product_indications = $term_wrapper->field_indications->value();
      foreach ($product_indications as $product_indication) {
        if ($product_indication) {
          if (!in_array($product_indication->tid, $indications)) {
            array_push($indications, $product_indication->tid);
          }
        }
      }
    }
  }

  return $indications;
}

/**
 * Getting the entries per account product endication.
 */
function get_entries($accounts, $products, $indications, $reps = array())
{
  $entries = [];
  if (!isset($accounts) || empty($accounts) || !isset($products) || empty($products)) {
    return $entries;
  }
  global $user;
  // If the report is type of transaction.
  if (isset($indications) && sizeof($indications) > 0) {
    // kpr($indications);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'entry')
      ->fieldCondition('field_account', 'target_id', $accounts, 'IN')
      ->fieldCondition('field_product', 'target_id', $products, 'IN')
      ->fieldCondition('field_indication', 'target_id', $indications, 'IN')
      ->fieldCondition('field_entry_type', 'value', 'patient', '=')
      ->addMetaData('account', user_load(1));

    if (isset($reps) && !empty($reps) && (count($reps) != 1 || $reps[0] != $user->uid)) {
      $query->propertyCondition('uid', $reps, 'IN');
    }
    $nodes = $query->execute();
    // Extract ids from the nodes.
    if (!empty($nodes)) {
      $entries = array_keys($nodes['node']);
    }
  }
  // If the records for usd consumption.
  else {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'entry')
      ->fieldCondition('field_account', 'target_id', $accounts, 'IN')
      ->fieldCondition('field_product', 'target_id', $products, 'IN')
      ->fieldCondition('field_entry_type', 'value', 'stocks', '=')
      ->addMetaData('account', user_load(1));

    if (isset($reps) && !empty($reps) && (count($reps) != 1 || $reps[0] != $user->uid)) {
      $query->propertyCondition('uid', $reps, 'IN');
    }
    $nodes = $query->execute();
    // Extract ids from the nodes.
    if (!empty($nodes)) {
      $entries = array_keys($nodes['node']);
    }
  }

  return $entries;
}

/**
 * Targets RESOURCES.
 */

/**
 * Get structured entries records for selected year.
 */
function get_entries_records_for_year($entries, $year, $boundle)
{
  $dates = get_year_dates($year);
  // Setting the start date is the first day of the selected year.
  $start_date = $dates['start_date'];
  // Setting the end date is the last day of the selected year.
  $end_date = $dates['end_date'];

  $entries_records = [];
  if (isset($entries)) {
    foreach ($entries as $entry) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'entry_month_record')
        ->entityCondition('bundle', $boundle)
        ->fieldCondition('field_entry', 'target_id', $entry, '=')
        ->fieldCondition('field_entry_date', 'value', $start_date, '>=')
        ->fieldCondition('field_entry_date', 'value', $end_date, '<=')
        ->fieldOrderBy('field_entry_date', 'value')
        ->addMetaData('account', user_load(1));

      $records = $query->execute();

      if (!empty($records)) {
        $records_ids = array_keys($records['entry_month_record']);

        // Adding each records for an entry in the array of entry id.
        $entries_records[$entry] = $records_ids;
      }
    }
  }

  return $entries_records;
}

/**
 * Get flat array of entries records for selected year.
 */
function get_flat_entries_records_for_year($entries, $year, $bundle)
{

  $dates = get_year_dates($year);
  // Setting the start date is the first day of the selected year.
  $start_date = $dates['start_date'];
  // Setting the end date is the last day of the selected year.
  $end_date = $dates['end_date'];

  if (!empty($entries)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'entry_month_record')
      ->entityCondition('bundle', $bundle)
      ->fieldCondition('field_entry', 'target_id', $entries, 'IN')
      ->fieldCondition('field_entry_date', 'value', $start_date, '>=')
      ->fieldCondition('field_entry_date', 'value', $end_date, '<=')
      ->fieldOrderBy('field_entry_date', 'value')
      ->addMetaData('account', user_load(1));
    $records = $query->execute();
    if (!empty($records)) {
      $records_ids = array_keys($records['entry_month_record']);
      // Adding each records for an entry in the array of entry id.
    }
  } else {
    return [];
  }

  return $records_ids;
}

/**
 * Sum records per indication or product.
 */
function sum_records_per_field($entries_records, $field_name, $is_stocks = FALSE)
{

  $reports = [];

  foreach ($entries_records as $entry => $records) {

    $entry_loaded = node_load($entry);
    $entry_loaded_wrapper = entity_metadata_wrapper('node', $entry_loaded);

    // Getting the name of the indication or the product.
    $indication_or_product = $entry_loaded_wrapper->{$field_name}->value();
    if (isset($indication_or_product->name)) {
      $name = $indication_or_product->name;
    } else {
      $name = $indication_or_product[0]->name;
    }
    // If the indication is not init yet so create new array of monthes for it.
    if (!isset($reports[$name])) {
      $reports[$name] = [];
      $months = [
        'December', 'January', 'February', 'March', 'April', 'May', 'June',
        'July', 'August', 'September', 'October', 'November'
      ];
      foreach ($months as $month) {
        $zeros = [0, 0];
        if (!$is_stocks) {
          array_push($zeros, 0);
        }
        $reports[$name][$month] = $zeros;
      }
    }

    $records_loaded = entity_load("entry_month_record", $records);

    foreach ($records_loaded as $id => $record) {
      $record_loaded_wrapper = entity_metadata_wrapper('entry_month_record', $record);
      $timestamp = $record_loaded_wrapper->field_entry_date->value();
      $date = getdate($timestamp);
      $month = $date['month'];
      if ($is_stocks) {
        if (!isset($reports[$name][$month][2])){
          array_push($reports[$name][$month], 0);
        }
        $reports[$name][$month][0] += $record_loaded_wrapper->field_stocks->value();
        $reports[$name][$month][1] += $record_loaded_wrapper->field_consumption->value();
        $usd_consumption = get_usd_consumption_per_record_id($id,'consumption');
        $reports[$name][$month][2] += (int)$usd_consumption;
        $usd_stocks = get_usd_consumption_per_record_id($id,'stocks');
        $reports[$name][$month][3] += (int)$usd_stocks;
      } else {
        $reports[$name][$month][0] += $record_loaded_wrapper->field_current_month_total->value();
        $reports[$name][$month][1] += $record_loaded_wrapper->field_current_month_new->value();
        $reports[$name][$month][2] += $record_loaded_wrapper->field_current_month_dropped->value();
        $reports[$name][$month][3] += $record_loaded_wrapper->field_current_month_dropped->value();
      }
    }
  }
  foreach ($reports as $product_name => $months){
    foreach ($months as $index => $month) {
      if (count($month) == 4) {
        if (isset($month[2])) {
          $reports[$product_name][$index][2] = number_format($month[2], 0, '','')+0;
        }
        if (isset($month[3])) {
          $reports[$product_name][$index][3] = number_format($month[3], 0, '','')+0;
        }
      }
    }
  }
  return $reports;
}

/**
 * Sums records per field grouped by account.
 */
function sum_records_per_field_grouped_by_account($entries_records, $field_name)
{

  $reports = [];

  foreach ($entries_records as $entry => $records) {

    $entry_loaded = node_load($entry);
    $entry_loaded_wrapper = entity_metadata_wrapper('node', $entry_loaded);

    // Getting the name of the indication or the product.
    $account = $entry_loaded_wrapper->field_account->value();

    $indication_or_product = $entry_loaded_wrapper->{$field_name}->value();
    if (isset($indication_or_product->name)) {
      $name = $indication_or_product->name;
    } else {
      $name = $indication_or_product[0]->name;
    }
    if (isset($account->title)) {
      $account_name = $account->title;
    } else {
      $account_name = $account[0]->title;
    }
    // If the indication is not init yet so create new array of monthes for it.
    if (!isset($reports[$account_name])) {
      $reports[$account_name] = [];
      $reports[$account_name]["consumptions"] = [];
      $reports[$account_name]["stocks"] = [];
    }
    if (!isset($reports[$account_name]["consumptions"][$name])) {
      $reports[$account_name]["consumptions"][$name] = [];
      $months = [
        'January', 'February', 'March', 'April', 'May', 'June',
        'July', 'August', 'September', 'October', 'November', 'December',
      ];
      foreach ($months as $month) {
        $reports[$account_name]["consumptions"][$name][$month] = [0];
        $reports[$account_name]["stocks"][$name][$month] = [0];
      }
    }
    // accounts:{products:{consumption:{months:[value]}}}.
    $records_loaded = entity_load("entry_month_record", $records);

    foreach ($records_loaded as $id => $record) {
      $record_loaded_wrapper = entity_metadata_wrapper('entry_month_record', $record);
      $timestamp = $record_loaded_wrapper->field_entry_date->value();
      $date = getdate($timestamp);
      $month = $date['month'];
      $reports[$account_name]["stocks"][$name][$month][0] += $record_loaded_wrapper->field_stocks->value();
      $reports[$account_name]["consumptions"][$name][$month][0] += $record_loaded_wrapper->field_consumption->value();
    }
  }

  return $reports;
}

/**
 * Custom callback function.
 */
function get_usd_consumption_per_record_id($record_id,$type)
{
  if (!isset($record_id)) {
    return 0;
  }

  $record = entity_load("entry_month_record", array($record_id));
  $record = array_pop($record);
  $record_wrapper = entity_metadata_wrapper("entry_month_record", $record);
  $record_date = $record_wrapper->field_entry_date->value();
  if ($type == 'consumption'){
    $record_consumption = $record_wrapper->field_consumption->value();
  } else {
    $record_stocks = $record_wrapper->field_stocks->value();
  }
  $entry = $record_wrapper->field_entry->value();
  $entry_wrapper = entity_metadata_wrapper("node", $entry);
  $account = $entry_wrapper->field_account->value();
  $products = $entry_wrapper->field_product->value();
  $account_id = $account->nid;
  foreach ($products as $product) {
    $products_ids[] = $product->tid;
  }
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'pricelist')
    ->fieldCondition('field_pricelist_account', 'target_id', $account_id, '=')
    ->addMetaData('account', user_load(1));
  $result = $query->execute();

  if (isset($result['node'])) {
    $pricelist = array_pop($result['node']);
    $pricelist = node_load($pricelist->nid);
    $pricelist_wrapper = entity_metadata_wrapper("node", $pricelist);
    $product_prices = $pricelist_wrapper->field_products_price->value();

    if (!empty($product_prices)) {
      $product_price_max = FALSE;
      foreach ($product_prices as $product_price) {
        $product_price_wrapper = entity_metadata_wrapper("field_collection_item", $product_price);
        $product = $product_price_wrapper->field_pricelist_product->value();
        $start_date = $product_price_wrapper->field_start_date->value();
        foreach ($products_ids as $tid) {
          if ($product->tid == $tid && $start_date <= $record_date) {
            if (
              !$product_price_max ||
              $product_price_max->field_start_date->value() < $start_date
            ) {
              $product_price_max = $product_price_wrapper;
            }
          }
        }
      }
      if ($product_price_max) {
        $price = $product_price_max->field_pricelist_price->value();
        if ($type == 'consumption'){
          return $price * $record_consumption;
        } else {
          return $price * $record_stocks;
        }
      }
    }
  }

  return 0;
}

/**
 * Target Report - Account.
 */
function ppt_resources_get_target_account($data)
{

  if (!isset($data['year'])) {
    return services_error('Missing Parameters!', 403);
  }

  if (isset($data['uid'])) {
    $uid = $data['uid'];
  } else {
    global $user;
    $uid = $user->uid;
  }

  if (isset($data['countries'])) {
    $countries = $data['countries'];
  } else {
    $countries = get_user_countries($user);
  }

  if (isset($data['reps'])) {
    $reps = $data['reps'];
  } else {
    $reps = array();
  }

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }

  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = $data['products'];
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid);
    } else {
      $products = get_target_products_for_accounts($accounts);
    }
  }

  $year = $data['year'];

  $months = array(
    "12" => 'December',
    "01" => 'January',
    "02" => 'February',
    "03" => 'March',
    "04" => 'April',
    "05" => 'May',
    "06" => 'June',
    "07" => 'July',
    "08" => 'August',
    "09" => 'September',
    "10" => 'October',
    "11" => 'November',
  );

  $target_nodes = get_targets_node_per_year($year, $countries);

  $big_array = [];
  foreach ($products as $product) {
    $parents = array_keys(taxonomy_get_parents($product));
    // Get target on the months.
    $target_cots = [
      "12" => 0,
      "01" => 0,
      "02" => 0,
      "03" => 0,
      "04" => 0,
      "05" => 0,
      "06" => 0,
      "07" => 0,
      "08" => 0,
      "09" => 0,
      "10" => 0,
      "11" => 0,
    ];
    $target_nprs = [
      "12" => 0,
      "01" => 0,
      "02" => 0,
      "03" => 0,
      "04" => 0,
      "05" => 0,
      "06" => 0,
      "07" => 0,
      "08" => 0,
      "09" => 0,
      "10" => 0,
      "11" => 0,
    ];
    foreach ($target_nodes as $month_number => $nodes) {
      $month_number = sprintf('%02d', $month_number);
      foreach ($nodes as $node) {
        foreach ($node->field_targets[LANGUAGE_NONE] as $fc_item) {
          $fc = field_collection_item_load($fc_item['value']);
          $ids = array_map(
            function ($item) {
              return $item["target_id"];
            },
            $fc->field_targets_product[LANGUAGE_NONE]
          );
          if (in_array($fc->field_targets_account[LANGUAGE_NONE][0]['target_id'], $accounts) && (in_array($product, $ids) || in_array($fc->field_targets_product[LANGUAGE_NONE][0]['target_id'], $parents))) {
            if (count($reps) == 0) {
              $target_cots[$month_number] += $fc->field_targets_cot[LANGUAGE_NONE][0]['value'];
              $target_nprs[$month_number] += $fc->field_targets_npr[LANGUAGE_NONE][0]['value'];
            } elseif (count($reps) > 0 && isset($fc->field_targets_rep[LANGUAGE_NONE])) {
              if (in_array($fc->field_targets_rep[LANGUAGE_NONE][0]['target_id'], $reps)) {
                $target_cots[$month_number] += $fc->field_targets_cot[LANGUAGE_NONE][0]['value'];
                $target_nprs[$month_number] += $fc->field_targets_npr[LANGUAGE_NONE][0]['value'];
              }
            }
          }
        }
      }
    }

    // Get all users patient entries.
    $actuals = get_entries_per_product_account($accounts, array($product), $year, $countries, $reps);
    $actual_targets_cot = $actuals[0];
    $actual_targets_npr = $actuals[1];
    for ($i = 1; $i <= 12; $i++) {
      $formatted_month_no = sprintf('%02d', $i);
      if (!isset($actual_targets_cot[$formatted_month_no])) {
        $actual_targets_cot[$formatted_month_no] = 0;
      }
      if (!isset($actual_targets_npr[$formatted_month_no])) {
        $actual_targets_npr[$formatted_month_no] = 0;
      }
    }

    $final_array = ['cot' => [], 'npr' => []];
    foreach ($months as $month => $month_name) {
      $final_array['cot']['Actual'][$month_name] = [$actual_targets_cot[$month]];
      $final_array['cot']['Target'][$month_name] = [$target_cots[$month]];
      $final_array['npr']['Actual'][$month_name] = [$actual_targets_npr[$month]];
      $final_array['npr']['Target'][$month_name] = [$target_nprs[$month]];
    }
    $product = taxonomy_term_load($product);
    $big_array[$product->name] = $final_array;
  }
  return $big_array;
}

/**
 * Retrive entries of accounts and products in year per countries.
 */
function get_entries_per_product_account($accounts, $products, $year, $countries, $reps = [])
{
  if (!isset($accounts) || !isset($products)) {
    return NULL;
  }
  if (!isset($year)) {
    $year = date('Y');
  }

  // Get all terms under the provided products.
  $subProducts = [];
  foreach ($products as $product) {
    $terms = taxonomy_get_children($product);
    if (empty($terms)) {
      $subProducts[] = $product;
    } else {
      foreach ($terms as $term) {
        if (!in_array($term->tid, $subProducts)) {
          $subProducts[] = $term->tid;
        }
      }
    }
  }

  $start_date = mktime(0, 0, 0, 11, 1, $year - 1);
  $end_date = mktime(0, 0, 0, 10, 31, $year);
  // Get country users.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    ->entityCondition('bundle', 'user')
    ->fieldCondition('field_country', 'target_id', $countries, 'IN')
    ->propertyCondition('status', 1)
    ->addMetaData('account', user_load(1));

  if (count($reps) != 0) {
    $query->propertyCondition('uid', $reps, 'IN');
  }
  $records = $query->execute();
  if (!isset($records['user'])) {
    return [];
  }
  $reps = array_keys($records['user']);
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'entry')
    ->fieldCondition('field_product', 'target_id', $subProducts, 'IN')
    ->fieldCondition('field_account', 'target_id', $accounts, 'IN')
    ->fieldCondition('field_entry_type', 'value', 'patient', '=')
    ->propertyCondition('uid', $reps, 'IN')
    ->addMetaData('account', user_load(1));

  $records = $query->execute();

  $actual_cots = [];
  $actual_nprs = [];
  if (isset($records['node'])) {
    $ids = array_keys($records['node']);
    $dates = get_year_dates($year);
    $start_date = $dates['start_date'];
    $end_date = $dates['end_date'];
    // Load the sub entries to get the cot.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'entry_month_record')
      ->entityCondition('bundle', 'entry_month_record')
      ->fieldCondition('field_entry', 'target_id', $ids, 'IN')
      ->fieldCondition('field_entry_date', 'value', $start_date, '>=')
      ->fieldCondition('field_entry_date', 'value', $end_date, '<=')
      ->addMetaData('account', user_load(1));

    $trans = $query->execute();
    if (isset($trans['entry_month_record'])) {
      $entities = entity_load("entry_month_record", array_keys($trans['entry_month_record']));
      foreach ($entities as $entity) {
        if (isset($entity->field_current_month_total[LANGUAGE_NONE])) {
          $cot = $entity->field_current_month_total[LANGUAGE_NONE][0]['value'];
          $npr = $entity->field_current_month_new[LANGUAGE_NONE][0]['value'];
          $month = date("m", strtotime($entity->field_entry_date[LANGUAGE_NONE][0]['value']));
          if (!isset($actual_cots[$month])) {
            $actual_cots[$month] = 0;
          }
          if (!isset($actual_nprs[$month])) {
            $actual_nprs[$month] = 0;
          }
          $actual_cots[$month] += $cot;
          $actual_nprs[$month] += $npr;
        }
      }
    }
    return [$actual_cots, $actual_nprs];
  }
  return [];
}

/**
 * Function to retrive all users from a country.
 */
function get_country_reps($country)
{
  if (!$country) {
    return NULL;
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    ->entityCondition('bundle', 'user')
    ->fieldCondition('field_country', 'target_id', $country, '=')
    ->propertyCondition('status', 1)
    ->addMetaData('account', user_load(1));

  $records = $query->execute();
  if (isset($records['user'])) {
    return array_keys($records['user']);
  }
  return array();
}

/**
 * Function to retrive the users entries.
 */
function get_users_entries($users, $year, $bundle = 'entry_month_record')
{
  if (!$users) {
    return NULL;
  }
  if (!isset($year)) {
    $year = date('Y');
  }
  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'entry_month_record')
    ->entityCondition('bundle', $bundle)
    ->fieldCondition('field_entry_date', 'value', $start_date, '>=')
    ->fieldCondition('field_entry_date', 'value', $end_date, '<=')
    ->propertyCondition('uid', $users, 'IN')
    ->addMetaData('account', user_load(1));

  $records = $query->execute();
  if (isset($records[$bundle])) {
    return entity_load("entry_month_record", array_keys($records[$bundle]));
  }
  return array();
}

/**
 * Function to retrive all accounts in a country.
 */
function get_country_accounts($country)
{
  if (!$country) {
    return array();
  }
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'account')
    ->fieldCondition('field_country', 'target_id', $country)
    ->addMetaData('account', user_load(1));

  $records = $query->execute();
  if (isset($records['node'])) {
    return entity_load("node", array_keys($records['node']));
  }
  return array();
}

/**
 * Function to retrive all products ids of an account.
 */
function get_account_products($account)
{
  if (!$account) {
    return array();
  }

  $account = node_load($account);
  $ids = array();
  if (isset($account->field_products[LANGUAGE_NONE])) {
    foreach ($account->field_products[LANGUAGE_NONE] as $item) {
      $ids[] = $item['target_id'];
    }
    return $ids;
  }

  return array();
}

/**
 * Function to retrive all targets nodes of that year, sort them by month.
 */
function get_targets_node_per_year($year, $countries, $users = array())
{
  if (!$year) {
    $year = date('Y');
  }

  if (count($users) == 0) {
    global $user;
    $users[] = $user->uid;
  }

  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'monthly_target')
    ->fieldCondition('field_target_country', 'target_id', $countries, 'IN')
    ->fieldCondition('field_targets_date', 'value', $start_date, '>=')
    ->fieldCondition('field_targets_date', 'value', $end_date, '<=')
    ->addMetaData('account', user_load(1));

  if (is_sales_manager($user)) {
    $query->fieldCondition('field_sales_manager', 'target_id', $users, 'IN');
  } elseif (is_regional_lead($user)) {
    $managers = ppt_resources_get_regional_lead_sales_managers($user->uid);
    $uids = array();
    foreach ($managers as $manager) {
      $uids[] = $manager->uid;
    }
    $query->fieldCondition('field_sales_manager', 'target_id', $uids, 'IN');
  } elseif (is_comm_lead($user)) {
    $managers = ppt_resources_get_comm_lead_sales_managers($user->uid);
    $uids = array();
    foreach ($managers as $manager) {
      $uids[] = $manager->uid;
    }
    $query->fieldCondition('field_sales_manager', 'target_id', $uids, 'IN');
  } else {
    // Do nothing, just get all targets of that country.
  }

  $records = $query->execute();

  if (isset($records['node'])) {
    $targets = array();
    foreach ($records['node'] as $nid => $item) {
      $node = node_load($nid);
      if (isset($node->field_targets_date[LANGUAGE_NONE]) && isset($node->field_targets[LANGUAGE_NONE])) {
        $node_date = $node->field_targets_date[LANGUAGE_NONE][0]['value'];
        $node_month = date("m", strtotime($node_date));
        $targets[$node_month][] = $node;
      }
    }
    return $targets;
  }
}

/**
 * Resource to retrive allowed clusters for a user.
 */
function ppt_resources_get_user_clusters($data)
{

  global $user;
  if ($user->uid == 0) {
    return services_error('Access Denied!', 403);
  }
  if (!isset($data['region'])) {
    return services_error('Missing Region!', 403);
  }
  $region = $data['region'];
  $clusters = array();
  $countries = get_user_countries($user);

  // Loop over the countries to get the clusters.
  foreach ($countries as $country) {
    $country_term = taxonomy_term_load($country);
    if (!isset($country_term->field_cluster[LANGUAGE_NONE])) {
      continue;
    }
    $cluster = $country_term->field_cluster[LANGUAGE_NONE][0]['target_id'];
    $cluster_term = taxonomy_term_load($cluster);
    if (!isset($cluster_term->field_region[LANGUAGE_NONE])) {
      continue;
    }
    $region_term = taxonomy_term_load($cluster_term->field_region[LANGUAGE_NONE][0]['target_id']);
    if (!isset($clusters[$cluster]) && $region == $region_term->tid) {
      $clusters[$cluster] = array('id' => $cluster, 'name' => $cluster_term->name);
    }
  }
  return $clusters;
}

/**
 * Resource to retrive allowed countries per cluster for a user.
 */
function ppt_resources_get_user_countries_per_cluster($data)
{
  global $user;
  if ($user->uid == 0) {
    return services_error('Access Denied!', 403);
  }
  if (!isset($data['clusters'])) {
    return services_error('missing clusters!', 403);
  }
  $clusters = $data['clusters'];
  $countries = get_user_countries($user);
  // Loop over the countries to get the clusters.
  $clusters_countries = [];
  foreach ($countries as $country) {
    $country_term = taxonomy_term_load($country);
    if (!isset($country_term->field_cluster[LANGUAGE_NONE])) {
      continue;
    }
    $cluster_term_id = $country_term->field_cluster[LANGUAGE_NONE][0]['target_id'];
    if (in_array($cluster_term_id, $clusters)) {
      $clusters_countries[$cluster_term_id][] = ['id' => $country_term->tid, 'name' => $country_term->name];
    }
  }
  return $clusters_countries;
}

/**
 * Function  to retrive allowed countries for a user.
 */
function get_user_countries($user = NULL)
{
  if (!$user) {
    global $user;
  }

  $countries = array();
  if (is_rep($user)) {
    // Load current user.
    $loaded_user = user_load($user->uid);
    $loaded_user_wrapper = entity_metadata_wrapper('user', $loaded_user);
    $countries_terms = $loaded_user_wrapper->field_country->value();
    foreach ($countries_terms as $item) {
      $countries[] = $item->tid;
    }
  } // Get reps for comm_lead
  elseif (is_comm_lead($user)) {
    $reps = ppt_resources_get_comm_lead_reps($user->uid);
    foreach ($reps as $rep) {
      if (!isset($rep->field_country[LANGUAGE_NONE])) {
        continue;
      }
      // Loop over the user countries.
      foreach ($rep->field_country[LANGUAGE_NONE] as $item) {
        if (!isset($countries[$item['target_id']])) {
          $countries[] = $item['target_id'];
        }
      }
    }
  }
  // If the logged in user is a sales manager.
  elseif (is_sales_manager($user)) {
    // Get reps of sales manager.
    $reps = ppt_resources_get_sales_manager_reps($user->uid);
    foreach ($reps as $rep) {
      if (!isset($rep->field_country[LANGUAGE_NONE])) {
        continue;
      }
      // Loop over the user countries.
      foreach ($rep->field_country[LANGUAGE_NONE] as $item) {
        if (!isset($countries[$item['target_id']])) {
          $countries[] = $item['target_id'];
        }
      }
    }
  } elseif (is_regional_lead($user)) {
    $managers = ppt_resources_get_regional_lead_sales_managers($user->uid);
    $reps = array();
    foreach ($managers as $manager) {
      $reps_tmp = ppt_resources_get_sales_manager_reps($manager->uid);
      $reps = array_merge($reps, $reps_tmp);
    }
    foreach ($reps as $rep) {
      if (!isset($rep->field_country[LANGUAGE_NONE])) {
        continue;
      }
      // Loop over the user countries.
      foreach ($rep->field_country[LANGUAGE_NONE] as $item) {
        if (!isset($countries[$item['target_id']])) {
          $countries[] = $item['target_id'];
        }
      }
    }
  } elseif (is_global_lead($user)) {
    $vocabulary = taxonomy_vocabulary_machine_name_load('country');
    $countries = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
    $countries = array_keys($countries);
  } elseif (is_data_admin($user)) {
    $account = user_load($user->uid);
    if (!isset($account->field_country[LANGUAGE_NONE])) {
      $countries = array();
    } else {
      foreach ($account->field_country[LANGUAGE_NONE] as $row) {
        $countries[] = $row['target_id'];
      }
    }
  } else {
    $vocabulary = taxonomy_vocabulary_machine_name_load('country');
    $countries = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
    $countries = array_keys($countries);
  }
  return array_unique($countries);
}

/**
 * Resource to retrive all products of given accounts.
 */
function ppt_resources_get_accounts_products($data)
{
  global $user;
  if (!isset($data['accounts']) || empty($data['accounts'])) {
    $countries = get_user_countries($user);
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  } else {
    $accounts = $data['accounts'];
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'account')
    ->propertyCondition('nid', $accounts, 'IN')
    ->addMetaData('account', user_load(1));

  $accounts = $query->execute();
  if (!isset($accounts['node'])) {
    return array();
  }

  $accounts = entity_load("node", array_keys($accounts['node']));

  $products = array();
  foreach ($accounts as $account) {
    if (isset($account->field_products[LANGUAGE_NONE])) {
      foreach ($account->field_products[LANGUAGE_NONE] as $item) {
        if (!isset($products[$item['target_id']]) && taxonomy_get_parents($item['target_id'])) {

          $product = taxonomy_term_load($item['target_id']);
          $products[$product->tid] = array("id" => $product->tid, "name" => $product->name);
        }
      }
    }
  }
  return $products;
}

/**
 * Resource to retrive all products of given accounts.
 */
function ppt_resources_get_target_accounts_products($data)
{
  global $user;
  if (!isset($data['accounts']) || empty($data['accounts'])) {
    $countries = get_user_countries($user);
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  } else {
    $accounts = $data['accounts'];
  }
  if (!is_array($accounts)) {
    $accounts = [$accounts];
  }

  $reps = array();
  if (isset($data['reps']) && !empty($data['reps'])) {
    $reps = $data['reps'];
  }

  if (empty($reps)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'account')
      ->propertyCondition('nid', $accounts, 'IN')
      ->addMetaData('account', user_load(1));

    $accounts = $query->execute();
    if (!isset($accounts['node'])) {
      return array();
    }
    $accounts = entity_load("node", array_keys($accounts['node']));
  } else {
    $reps = entity_load("user", $reps);

    $accounts = array();
    foreach ($reps as $rep) {
      if (isset($rep->field_account_product_date[LANGUAGE_NONE])) {
        foreach ($rep->field_account_product_date[LANGUAGE_NONE] as $item) {
          $fc = entity_load('field_collection_item', array($item['value']));
          $accountId = $fc[$item['value']]->field_account[LANGUAGE_NONE][0]['target_id'];
          if (!isset($accounts[$accountId])) {
            $accounts[$accountId] = $accountId;
          }
        }
      }
    }

    $accounts = entity_load("node", array_keys($accounts));
  }

  $products = array();

  foreach ($accounts as $account) {
    if (isset($account->field_products[LANGUAGE_NONE])) {
      foreach ($account->field_products[LANGUAGE_NONE] as $item) {
        $parents = taxonomy_get_parents($item['target_id']);
        // This is a parent.
        if (empty($parents)) {
          $term = taxonomy_term_load($item['target_id']);
          if (!isset($products[$term->tid]) && !empty($term->tid)) {
            $products[$term->tid] = array(
              "id" => $term->tid,
              "name" => $term->name,
              "terms" => array(),
            );
          }
          $children = taxonomy_get_children($item['target_id']);
          foreach ($children as $child) {
            if (!isset($products[$term->tid]['terms'][$child->tid])) {
              $products[$term->tid]['terms'][$child->tid] = array("id" => $child->tid, "name" => $child->name);
            }
          }
        }
        // This is a child.
        else {
          foreach ($parents as $key => $parent) {
            if (!isset($products[$key])) {
              $products[$key] = array(
                "id" => $parent->tid,
                "name" => $parent->name,
                "terms" => array(),
              );
            }
            $term = taxonomy_term_load($item['target_id']);
            if (!isset($products[$key]['terms'][$term->tid])) {
              $products[$key]['terms'][$term->tid] = array("id" => $term->tid, "name" => $term->name);
            }
          }
        }
      }
    }
  }
  return $products;
}

/**
 * Resource to get all reps of countries and accounts under logged in user.
 */
function ppt_resources_get_reps_of_accounts_country($data)
{
  global $user;
  if (!isset($data['countries']) || empty($data['countries'])) {
    $countries = get_user_countries($user);
  } else {
    $countries = $data['countries'];
  }

  if (!isset($data['accounts']) || empty($data['accounts'])) {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  } else {
    $accounts = $data['accounts'];
  }
  if (!is_array($accounts)) {
    $accounts = [$accounts];
  }
  $reps = array();
  $final = array();
  if (is_sales_manager($user)) {
    // If the user is sales manager we will get the reps under it.
    $reps = ppt_resources_get_sales_manager_reps($user->uid, $countries);
    foreach ($reps as $rep_user) {
      // Get full name.
      if (isset($rep_user->field_full_name[LANGUAGE_NONE])) {
        $name = $rep_user->field_full_name[LANGUAGE_NONE][0]['value'];
      } else {
        $name = $rep_user->name;
      }
      $final[] = array("id" => $rep_user->uid, "name" => $name);
    }
    $final2 = ppt_resources_get_reps_of_accounts($final, $accounts);
    return $final2;
  } elseif (is_comm_lead($user)) {
    $reps = ppt_resources_get_comm_lead_reps($user->uid, $countries);
    foreach ($reps as $rep_user) {
      // Get full name.
      if (isset($rep_user->field_full_name[LANGUAGE_NONE])) {
        $name = $rep_user->field_full_name[LANGUAGE_NONE][0]['value'];
      } else {
        $name = $rep_user->name;
      }
      $final[] = array("id" => $rep_user->uid, "name" => $name);
    }
    $final2 = ppt_resources_get_reps_of_accounts($final, $accounts);
    return $final2;
  } elseif (is_regional_lead($user)) {
    $uid = $user->uid;
    // Load all the sales manager for this regional lead and loop over them.
    $sales_managers = ppt_resources_get_regional_lead_sales_managers($uid);
    $reps = array();
    foreach ($sales_managers as $sales_manager) {
      $reps = array_merge($reps, ppt_resources_get_sales_manager_reps($sales_manager->uid, $countries));
    }
    // $reps = array_unique($reps);
    foreach ($reps as $rep_user) {
      if ($rep_user) {
        // Get full name.
        if (isset($rep_user->field_full_name[LANGUAGE_NONE])) {
          $name = $rep_user->field_full_name[LANGUAGE_NONE][0]['value'];
        } else {
          $name = $rep_user->name;
        }
        $final[] = array("id" => $rep_user->uid, "name" => $name);
      }
    }
    $final2 = ppt_resources_get_reps_of_accounts($final, $accounts);
    return $final2;
  } elseif (is_system_admin($user) || is_global_lead($user) || is_data_admin($user)) {
    foreach ($countries as $country) {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'user')
        ->entityCondition('bundle', 'user')
        ->fieldCondition('field_country', 'target_id', $country, '=')
        ->propertyCondition('status', 1)
        ->addMetaData('account', user_load(1));

      $records = $query->execute();
      if (isset($records['user'])) {
        $tmp = array();
        foreach ($records['user'] as $id => $row) {
          $rep = user_load($id);
          if ($rep && is_rep($rep)) {
            $tmp[] = $id;
          }
        }
        $reps = array_merge($reps, $tmp);
      }
    }
  } elseif (is_rep($user)) {
    $reps = array($user->uid);
  }

  // Load all users.
  $reps = array_unique($reps);
  foreach ($reps as $rep_id) {
    $rep_user = user_load($rep_id);
    if ($rep_user) {
      // Get full name.
      if (isset($rep_user->field_full_name[LANGUAGE_NONE])) {
        $name = $rep_user->field_full_name[LANGUAGE_NONE][0]['value'];
      } else {
        $name = $rep_user->name;
      }
      $final[] = array("id" => $rep_id, "name" => $name);
    }
  }
  $final2 = ppt_resources_get_reps_of_accounts($final, $accounts);
  return $final2;
}

/**
 * Resource to get all reps of countries and accounts under logged in user.
 */
function ppt_resources_get_accounts_indications($data)
{
  global $user;

  if (isset($data['countries'])) {
    $countries = $data['countries'];
  } else {
    $countries = get_user_countries($user);
  }

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }

  $products = array();
  foreach ($accounts as $account) {
    // Load account entity to get the products.
    $account_entity = node_load($account);
    if ($account_entity) {
      if (isset($account_entity->field_products[LANGUAGE_NONE])) {
        foreach ($account_entity->field_products[LANGUAGE_NONE] as $item) {
          if (!in_array($item['target_id'], $products)) {
            $products[] = $item['target_id'];
          }
        }
      }
    }
  }

  $indications = array();
  // Loop over products to get the indications.
  foreach ($products as $product_id) {
    if ($product = taxonomy_term_load($product_id)) {
      if (isset($product->field_indications[LANGUAGE_NONE])) {
        foreach ($product->field_indications[LANGUAGE_NONE] as $item) {
          if (!isset($indications[$item['target_id']])) {
            if ($indication = taxonomy_term_load($item['target_id'])) {
              $indications[$item['target_id']] = array("id" => $indication->tid, "name" => $indication->name);
            }
          }
        }
      }
    }
  }
  return $indications;
}

/**
 * Gets consumptions and stocks per product.
 */
function ppt_resources_get_consumptions_stocks_per_product($data)
{
  if (!isset($data['year']) || (!isset($data['uid']))) {
    return services_error('Year or UID are not defined!', 500);
  }

  global $user;
  $year = $data['year'];
  $accounts = [];
  // If there is no uid sent with the api so get the current user id.
  if (isset($data['uid']) && !empty($data['uid'])) {
    $uid = $data['uid'];
  } else {
    $uid = $user->uid;
  }
  $countries = array();
  if (isset($data['countries'])) {
    $countries = $data['countries'];
  }
  $reps = array();
  if (isset($data['reps'])) {
    $reps = $data['reps'];
  } else {
    $is_rep = FALSE;
    if (is_rep($user)) {
      $is_rep = TRUE;
    }
    $reps = ppt_resources_get_sales_manager_reps($uid, $countries, $is_rep);
  }

  $user = user_load($uid);

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }

  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = get_products_dosages($data['products']);
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid);
    } else {
      $products = get_products_for_accounts($accounts);
    }
  }

  $entries = get_entries($accounts, $products, NULL, $reps);
  $entries_records = get_entries_records_for_year($entries, $year, 'consumption_stock_entry');
  $consumptions = sum_records_per_field_grouped_by_account($entries_records, 'field_product');

  return $consumptions;
}

/**
 * Check if account products exist in products passed.
 */
function check_account_products($account, $product)
{
  $account_data = node_load($account);
  $children = array_keys(taxonomy_get_children($product));
  foreach ($account_data->field_products['und'] as $key => $value) {
    foreach ($value as $product_id => $product_value) {
      if (in_array($product_value, $children)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Target Report - Account.
 */
function ppt_resources_get_planned_orders($data)
{
  if (!isset($data['year'])) {
    return services_error('Missing Parameters!', 403);
  }

  if (isset($data['uid'])) {
    $uid = $data['uid'];
  } else {
    global $user;
    $uid = $user->uid;
  }

  if (isset($data['countries'])) {
    $countries = $data['countries'];
  } else {
    $countries = get_user_countries($user);
  }

  if (isset($data['reps'])) {
    $reps = $data['reps'];
  } else {
    $reps = array();
  }

  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries);
  }

  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = $data['products'];
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid);
    } else {
      $products = get_target_products_for_accounts($accounts);
    }
  }

  $year = $data['year'];
  $target_nodes = get_planned_orders_for_acconuts_per_year($year, $accounts);
  // Initialze empty months.
  $months = array(
    "01" => 'December',
    "02" => 'January',
    "03" => 'February',
    "04" => 'March',
    "05" => 'April',
    "06" => 'May',
    "07" => 'June',
    "08" => 'July',
    "09" => 'August',
    "10" => 'September',
    "11" => 'October',
    "12" => 'November',
  );
  $final_arr = [];
  // Consider a product exists with mutiple accounts.
  foreach ($target_nodes as $nid => $item) {
    $node = node_load($nid);
    $planned_product_tid = $node->field_planned_product[LANGUAGE_NONE][0]["target_id"];
    if (in_array($planned_product_tid, $products)) {
      $planned_product = taxonomy_term_load($planned_product_tid);
      $planned_product_name = $planned_product->name;
      // Get node values for product (planned and delivered).
      if (isset($node->field_planned_period[LANGUAGE_NONE])) {
        $node_date = $node->field_planned_period[LANGUAGE_NONE][0]['value'];
        $planned_month = date("F", strtotime($node_date));
      }

      $planned_quantity = 0;
      if (isset($node->field_planned_quantity[LANGUAGE_NONE])) {
        $planned_quantity = $node->field_planned_quantity[LANGUAGE_NONE][0]["value"];
      }

      if (isset($node->field_planned_actual_period[LANGUAGE_NONE])) {
        $node_date = $node->field_planned_actual_period[LANGUAGE_NONE][0]['value'];
        $delivery_month = date("F", strtotime($node_date));
      }

      $delivered_quantity = 0;
      if (isset($node->field_planned_delivered_quantity[LANGUAGE_NONE])) {
        $delivered_quantity = $node->field_planned_delivered_quantity[LANGUAGE_NONE][0]["value"];
      }
      // If product already exists, update its values for node months.
      if (isset($final_arr[$planned_product_name])) {
        if (isset($final_arr[$planned_product_name]["Planned"][$planned_month])) {
          $final_arr[$planned_product_name]["Planned"][$planned_month][0] += (int) $planned_quantity;
        } else {
          $final_arr[$planned_product_name]["Planned"][$planned_month][0] = [(int) $planned_quantity];
        }
        if (isset($final_arr[$planned_product_name]["Actual"][$delivery_month])) {
          $final_arr[$planned_product_name]["Actual"][$delivery_month][0] += (int) $delivered_quantity;
        } else {
          $final_arr[$planned_product_name]["Actual"][$delivery_month] = [(int) $delivered_quantity];
        }
      } else {
        // Initialze product array with 0 for all months, then update it with current node data.
        $final_arr[$planned_product_name] = ["Actual" => [], "Planned" => []];
        for ($i = 1; $i <= 12; $i++) {
          $month = $months[sprintf('%02d', $i)];
          $final_arr[$planned_product_name]["Actual"][$month] = [0];
          $final_arr[$planned_product_name]["Planned"][$month] = [0];
        }
        $final_arr[$planned_product_name]["Actual"][$delivery_month] = [(int) $delivered_quantity];
        $final_arr[$planned_product_name]["Planned"][$planned_month] = [(int) $planned_quantity];
      }
    }
  }

  // [product => [actual => [months], target => [months]]]
  return $final_arr;
}

/**
 * Gets planned orders for acconuts per year.
 */
function get_planned_orders_for_acconuts_per_year($year, $accounts)
{
  if (!$year) {
    $year = date('Y');
  }

  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];

  if (empty($accounts)) {
    return [];
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'planned_order')
    ->fieldCondition('field_planned_account', 'target_id', $accounts, 'IN')
    ->fieldCondition('field_planned_period', 'value', $start_date, '>=')
    ->fieldCondition('field_planned_period', 'value', $end_date, '<=')
    ->fieldCondition('field_planned_actual_period', 'value', $start_date, '>=')
    ->fieldCondition('field_planned_actual_period', 'value', $end_date, '<=')
    ->addMetaData('account', user_load(1));

  $records = $query->execute();

  if (isset($records['node'])) {
    return $records['node'];
  }
}

/**
 * Custom callback function.
 */
function ppt_resources_get_planned_products_report($data)
{
  $reports = [];
  $index = 0;
  foreach ($data['accounts'] as $account) {
    $count = 0;
    foreach ($data['products'] as $product) {
      $product_data = taxonomy_term_load($product);
      if (isset($product_data->parent)) {
        $reports[$index]["account_id"] = $account;
        $reports[$index]["account_name"] = node_load($account)->title;
        $reports[$index]["products"][$count]["product_id"] = $product;
        $reports[$index]["products"][$count]["product_name"] = $product_data->name;
        for ($i = 1; $i <= 12; $i++) {
          $date = NULL;
          if ($i < 10) {
            $date = $data['year'] . '-0' . $i . '-01';
          } elseif ($i == 10 || $i == 11) {
            $date = $data['year']  . $i . '-01'; //2020-10||11-01
          } else {
            $date = (((int)$data['year']) - 1) . '-' . $i . '-01'; //2019-12-01
          }
          //initialize
          $reports[$index]["products"][$count]['planned_quantity'][$i - 1] = 0;
          $reports[$index]["products"][$count]['delivered_quantity'][$i - 1] = 0;
          $reports[$index]["products"][$count]['stock'][$i - 1] = 0;
          $reports[$index]["products"][$count]['consumption'][$i - 1] = 0;
          $planned_nodes = ppt_resources_get_planned_order($account, $product, $data['reps'], $date, "planned-period");
          if (!empty($planned_nodes)) {
            $planned_orders_ids = array_keys($planned_nodes['node']);
            $planned_orders = node_load_multiple($planned_orders_ids);
            $planned_quantity = 0;
            foreach ($planned_orders as $planned_order) {
              $planned_quantity += $planned_order->field_planned_quantity['und'][0]['value'];
            }
            $reports[$index]["products"][$count]['planned_quantity'][$i - 1] = $planned_quantity;
          } else {
            $reports[$index]["products"][$count]['planned_quantity'][$i - 1] = 0;
          }
          $delivered_nodes = ppt_resources_get_planned_order($account, $product, $data['reps'], $date, "actual-period");
          if (!empty($delivered_nodes)) {
            $delivered_orders_ids = array_keys($delivered_nodes['node']);
            $delivered_orders = node_load_multiple($delivered_orders_ids);
            $delivered_quantity = 0;
            foreach ($delivered_orders as $delivered_order) {
              $delivered_quantity += $delivered_order->field_planned_delivered_quantity['und'][0]['value'];
            }
            $reports[$index]["products"][$count]['delivered_quantity'][$i - 1] = $delivered_quantity;
          } else {
            $reports[$index]["products"][$count]['delivered_quantity'][$i - 1] = 0;
          }
        }
        $planned_temp = $reports[$index]["products"][$count]['planned_quantity'];
        $planned_value_temp = array_slice($planned_temp, 11);
        array_pop($planned_temp);
        //        array_pop($planned_temp);
        $planned_temp = array_merge($planned_value_temp, $planned_temp);
        $reports[$index]["products"][$count]['planned_quantity'] = $planned_temp;
        $delivered_temp = $reports[$index]["products"][$count]['delivered_quantity'];
        $delivered_value_temp = array_slice($delivered_temp, 11);
        array_pop($delivered_temp);
        //        array_pop($delivered_temp);
        $delivered_temp = array_merge($delivered_value_temp, $delivered_temp);
        $reports[$index]["products"][$count]['delivered_quantity'] = $delivered_temp;
        $entries = ppt_resources_get_entries($account, [$product], $data['reps']);
        $entries_records = get_flat_entries_records_for_year($entries, $data['year'], 'consumption_stock_entry');
        $records_loaded = entity_load("entry_month_record", $entries_records);
        foreach ($records_loaded as $id => $record) {
          $month = (int) (explode("-", $record->field_entry_date['und'][0]['value'])[1]);
          if ($month == 12) {
            $i = 0;
          } else {
            $i = $month;
          }
          $reports[$index]["products"][$count]['stock'][$i] += (int)$record->field_stocks['und'][0]['value'];
          $reports[$index]["products"][$count]['consumption'][$i] += (int)$record->field_consumption['und'][0]['value'];
        }
        $count = $count + 1;
      }
    }
    $index = $index + 1;
  }
  return $reports;
}

/**
 * Resource to get all target quantity , delivered , value .
 */
function ppt_resources_target_delivered_report($data)
{
  global $user;
  $current_uid = $user->uid;
  // Varriables
  $date = [];
  if (isset($data['year'])) {
    $date = get_year_dates($data['year']);
  } else {
    $date = get_year_dates();
  }
  if (!isset($data['reps']) && !isset($data['accounts']) && !isset($data['therapeutic'])) {
    if (!isset($data['year'])) {
      $date = get_year_dates();
    } else {
      $date = get_year_dates($data['year']);
    }
    $user_products = get_products_for_current_user($current_uid);
    $user_accounts = get_accounts_for_current_user($current_uid);
    return get_target_delivered_report($current_uid, $user_accounts, $user_products, $date);
  }
  if (is_comm_lead($user)) {
    if (isset($data['team']) && !isset($data['reps'])) {
      if (is_array($data['team'])) {
        $data['team'] = $data['team'][0];
      }
      $data['reps'] = array_keys(ppt_resources_get_team_reps($data));
    }
  }
  if (!$data['reps']) {
    return "please enter reps";
  } elseif (!$data['accounts']) {
    return "please enter accounts";
  } elseif (!$data['therapeutic']) {
    return "please enter thermatic area";
  } else {
    if (!is_array($data['accounts'])) {
      $data['accounts'] = [$data['accounts']];
    }
    if (!is_array($data['therapeutic'])) {
      $data['therapeutic'] = [$data['therapeutic']];
    }
    $account_info = node_load_multiple($data['accounts']);
    $account_products_ids = [];
    foreach ($account_info as $info) {
      $account_products_array = $info->field_products['und'];
      foreach ($account_products_array as $product) {
        $account_products_ids[] = $product['target_id'];
      }
    }
    $thermatic_area_products_ids = get_thermatic_area_products_ids($data["therapeutic"]);
    if (isset($account_products_ids)) {
      foreach ($account_products_ids as $product_id) {
        if (isset($thermatic_area_products_ids)) {
          if (in_array($product_id, $thermatic_area_products_ids)) {
            $data['products'][] = $product_id;
          }
        } else {
          $data['products'] = [];
        }
      }
    } else {
      $data['products'] = [];
    }
    if (isset($data['products']) && !empty($data['products'])) {
      return get_target_delivered_report($data['reps'], $data['accounts'], $data['products'], $date);
    } else {
      return "there is no product match for that account with therapeutic area";
    }
  }
}

function get_target_delivered_report($reps, $accounts, $products, $date)
{
  $pricelist_items_ids = [];
  $acutal_period = [];
  $total = [];
  $data['reps'] = (!is_array($reps)) ? [$reps] : $reps;
  $data['accounts'] = $accounts;
  $data['products'] = $products;
  // Targets.
  $targets = get_targets($data['reps'], $data['accounts'], $data['products'], $date);
  if (isset($targets) && !empty($targets)) {
    foreach ($targets as $target) {
      // Load product.
      $product_id = $target->field_target_product['und'][0]['target_id'];
      $product = taxonomy_term_load($product_id);
      $product_name = $product->name;
      // Get target quantity.
      $target_quantity = $target->field_target_quantity['und'][0]['value'];
      // Check if the product exist in the total array.
      if (isset($total[$product_id])) {
        // aggregate the total.
        $total[$product_id]['target_quantity'] += $target_quantity;
      } else {
        $total[$product_id] = [
          'product_id' => $product_id,
          'product_name' => $product_name,
          'target_quantity' => (int)$target_quantity
        ];
      }
    }
  }
  if (isset($data['products']) && !empty($data['products'])) {
    foreach ($data['products'] as $product_id) {
      if (!in_array($product_id, array_keys($total))) {
        $product = taxonomy_term_load($product_id);
        $product_name = $product->name;
        $total[$product_id] = [
          'product_id' => $product_id,
          'product_name' => $product_name,
          'target_quantity' => 0
        ];
      }
    }
  }
  // Planned orders.
  $orders = get_planned_orders($data['reps'], $data['accounts'], $data['products'], $date);
  if (!empty($orders)) {
    foreach ($orders as $order) {
      // Load product.
      $product_id = $order->field_planned_product['und'][0]['target_id'];
      $product = taxonomy_term_load($product_id);
      $product_name = $product->name;
      $acutal_period[$product_id] = $order->field_planned_actual_period['und'][0]['value'];
      // Get delivered quantity.
      $delivered_quantity = $order->field_planned_delivered_quantity['und'][0]['value'];
      if (isset($total[$product_id]['delivered_quantity'])) {
        $total[$product_id]['delivered_quantity'] += $delivered_quantity;
      } else {
        $total[$product_id] = array_merge($total[$product_id], ['delivered_quantity' => (int)$delivered_quantity]);
      }
    }
  }
  // Check products without delivered_quantity.
  foreach ($data['products'] as $product_id) {
    if (!isset($total[$product_id]['delivered_quantity'])) {
      $total[$product_id] = array_merge($total[$product_id], ['delivered_quantity' => 0]);
    }
  }
  // Calculate NTM, (target - delvired).
  foreach (array_keys($total) as $value) {
    $NTM = (int)$total[$value]['target_quantity'] - (int)$total[$value]['delivered_quantity'];
    $total[$value] = array_merge($total[$value], ['ntm_quantity' => $NTM]);
  }
  // Price list .
  $price_list = get_pricelist($data['accounts'], $data['products']);
  // Make an array of field_products_price ids.
  if (isset($price_list)) {
    foreach ($price_list as $field_collection_items) {
      if (isset($field_collection_items->field_products_price['und'])) {
        foreach ($field_collection_items->field_products_price['und'] as $item) {
          array_push($pricelist_items_ids, $item['value']);
        }
      }
    }
  }
  $product_prices = [];
  // Load all fields.
  $load = entity_load('field_collection_item', $pricelist_items_ids);
  foreach ($data['products'] as $product_id) {
    foreach ($load as $item) {
      $info = [
        "product_id" => $item->field_pricelist_product['und'][0]['target_id'],
        "price" => ($item->field_pricelist_price['und'][0]['value']) ? ($item->field_pricelist_price['und'][0]['value']) : 0,
        "date" => $item->field_start_date['und'][0]['value']
      ];
      if ($info['product_id'] == $product_id) {
        if (isset($product_prices[$product_id])) {
          $product_prices[$product_id] = array_merge($product_prices[$product_id], [$info]);
        } else {
          $product_prices[$product_id] = [$info];
        }
      }
    }
  }
  // Add 0 price for any product has no price .
  foreach ($data['products'] as $product_id) {
    if (!in_array($product_id, array_keys($product_prices))) {
      $product_prices[$product_id] = [[
        'product_id' => $product_id,
        'price' => 0,
        'date' => date("Y-01-01 00:00:00")
      ]];
    }
  }
  //  return $acutal_period[];
  // Calculate value.
  foreach ($total as $total_value) {
    foreach ($product_prices as $product_price) {
      // Check the product id in the price list = product id in total to start calculate .
      if ($product_price[0]['product_id'] == $total_value['product_id']) {
        // If there is no delivered content then actual period = end date to Avoid null values.
        if (!isset($acutal_period[$total_value['product_id']])) {
          $acutal_period[$total_value['product_id']] = $date['end_date'];
        }
        // If the product has multiple price .
        if (count($product_price) > 1) {
          $temp = [];
          for ($x = 0; $x < count($product_price); $x++) {
            if ($date['start_date'] <= $product_price[$x]['date'] && $product_price[$x]['date'] <= $date['end_date'] && $product_price[$x]['date'] <= $acutal_period[$total_value['product_id']]) {
              if (count($temp) >= 1) {
                // If temp has date greater than current year .
                if ($temp['date'] > $date['end_date']) {
                  $temp = $product_price[$x];
                }
                // If temp has date greater than current date in the same year .
                if ($product_price[$x]['date'] > $temp['date']) {
                  $temp = $product_price[$x];
                }
              } else {
                $temp = $product_price[$x];
              }
            } elseif ($product_price[$x]['date'] < $date['start_date']) {
              if (count($temp) >= 1) {
                if ($temp['date'] > $date['end_date']) {
                  $temp = $product_price[$x];
                }
                if ($product_price[$x]['date'] > $temp['date']) {
                  $temp = $product_price[$x];
                }
              } else {
                $temp = $product_price[$x];
              }
            } else {
              if (count($temp) == 0) {
                $temp = $product_price[$x];
                $temp['price'] = 0;
              }
            }
          }
          $info = [
            'total_target_value' => number_format(($total_value['target_quantity'] * $temp['price']), 0,'', '')+0,
            'total_delivered_value' => number_format(($total_value['delivered_quantity'] * $temp['price']), 0, '', '')+0,
            'total_ntm_value' => number_format(($total_value['ntm_quantity'] * $temp['price']), 0, '', '')+0
          ];
          $total[$total_value['product_id']] = array_merge($total_value, $info);
          // If the product has single price in the same year.
        } elseif ($date['start_date'] <= $product_price[0]['date'] && $product_price[0]['date'] <= $date['end_date'] && $product_price[0]['date']) {
          $info = [
            'total_target_value' => number_format(($total_value['target_quantity'] * $product_price[0]['price']), 0, '', '')+0,
            'total_delivered_value' => number_format(($total_value['delivered_quantity'] * $product_price[0]['price']), 0, '', '')+0,
            'total_ntm_value' => number_format(($total_value['ntm_quantity'] * $product_price[0]['price']), 0, '', '')+0
          ];
          $total[$total_value['product_id']] = array_merge($total_value, $info);
          // If the product has single price in the year before .
        } elseif ($product_price[0]['date'] < $date['start_date']) {
          $info = [
            'total_target_value' => number_format(($total_value['target_quantity'] * $product_price[0]['price']), 0, '', '')+0,
            'total_delivered_value' => number_format(($total_value['delivered_quantity'] * $product_price[0]['price']), 0, '', '')+0,
            'total_ntm_value' => number_format(($total_value['ntm_quantity'] * $product_price[0]['price']), 0, '', '')+0
          ];
          $total[$total_value['product_id']] = array_merge($total_value, $info);
          // If the product has single price in the next year we ignore it.
        } else {
          $info = [
            'total_target_value' => $total_value['target_quantity'] * 0,
            'total_delivered_value' => $total_value['delivered_quantity'] * 0,
            'total_ntm_value' => $total_value['ntm_quantity'] * 0
          ];
          $total[$total_value['product_id']] = array_merge($total_value, $info);
        }
      }
    }
  }
  $target_quantity_value = array_column($total, 'target_quantity');
  array_multisort($target_quantity_value, SORT_DESC, $total);
  return array_values($total);
}

/**
 * Get the next planned orders per account and product.
 */
function ppt_resources_get_next_planned_orders($data)
{
  global $user;
  $months = array(
    "01" => 'December',
    "02" => 'January',
    "03" => 'February',
    "04" => 'March',
    "05" => 'April',
    "06" => 'May',
    "07" => 'June',
    "08" => 'July',
    "09" => 'August',
    "10" => 'September',
    "11" => 'October',
    "12" => 'November',
  );

  if (!isset($data['year'])) {
    return services_error('Year is not defined!', 500);
  }

  if (empty($data['accounts'])) {
    return services_error('Accounts is not defined!', 500);
  }

  if (empty($data['products'])) {
    return services_error('Products is not defined!', 500);
  }

  $year = $data['year'];
  $accounts = $data['accounts'];
  $products = $data['products'];
  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'planned_order')
    ->fieldCondition('field_planned_account', 'target_id', $accounts, 'IN')
    ->fieldCondition('field_planned_product', 'target_id', $products, 'IN')
    ->fieldCondition('field_planned_period', 'value', $start_date, '>=')
    ->fieldCondition('field_planned_period', 'value', $end_date, '<=')
    ->addMetaData('account', user_load(1));

  $records = $query->execute();
  $final_arr = [];

  if (isset($records['node'])) {
    $nodes_ids = array_keys($records['node']);
    $nodes = node_load_multiple($nodes_ids);

    foreach ($nodes as $node) {
      // Get node planned product name.
      $planned_product_tid = $node->field_planned_product['und'][0]['target_id'];
      $planned_product = taxonomy_term_load($planned_product_tid);
      $planned_product_name = $planned_product->name;

      // Get node date for product (planned).
      if (isset($node->field_planned_period['und'])) {
        $node_date = $node->field_planned_period['und'][0]['value'];
        $planned_month = date("F", strtotime($node_date));
      }

      // Get node values for planned quantity.
      $planned_quantity = 0;
      if (isset($node->field_planned_quantity['und'])) {
        $planned_quantity = $node->field_planned_quantity['und'][0]['value'];
      }

      // If product already exists, update its values for node months.
      if (isset($final_arr['planned'][$planned_product_name])) {
        if (isset($final_arr['planned'][$planned_product_name][$planned_month])) {
          $final_arr['planned'][$planned_product_name][$planned_month][0] += (int) $planned_quantity;
        } else {
          $final_arr['planned'][$planned_product_name][$planned_month][0] = [(int) $planned_quantity];
        }
      } else {
        // Initialze product array with 0 for all months, then update it with current node data.
        $final_arr['planned'][$planned_product_name] = [];
        for ($i = 1; $i <= 12; $i++) {
          $month = $months[sprintf('%02d', $i)];
          $final_arr['planned'][$planned_product_name][$month] = [0];
        }
        $final_arr['planned'][$planned_product_name][$planned_month] = [(int) $planned_quantity];
      }
    }
  }
  return $final_arr;
}

// Expected Orders API .
function expected_orders($data)
{
  global $user;
  $expected_orders = [];
  $user_id = $user->uid;
  $account_products_ids = [];
  if (!isset($data['accounts'])) {
    return services_error('accounts is not defined!', 500);
  } elseif (!isset($data['therapeutic'])) {
    return services_error('therapeutic area is not defined!', 500);
  } else {
    if (!isset($data['year'])) {
      $date = get_year_dates();
    } else {
      $date = get_year_dates($data['year']);
    }
    if (!isset($data['quarter'])) {
      $data['quarter'] = 1;
    }
    if (is_array($data['quarter'])) {
      $data['quarter'] = $data['quarter'][0];
    }
    if (is_array($data['therapeutic'])) {
      $data['therapeutic'] = $data['therapeutic'][0];
    }
    // Get reps;
    if (is_rep($user)) {
      $data['reps'] = (is_array($user_id)) ? $user_id : [$user_id];
    } elseif (is_sales_manager($user)) {
      $data['reps'] = ppt_resources_get_sales_manager_reps($user_id);
      $data['reps'] = (is_array($data['reps'])) ? $data['reps'] : [$data['reps']];
    } elseif (is_comm_lead($user)) {
      if (isset($data['team'])) {
        if (is_array($data['team'])) {
          $data['team'] = $data['team'][0];
          $data['reps'] = array_keys(ppt_resources_get_team_reps($data['team']));
        }
        $data['reps'] = (is_array($data['reps'])) ? $data['reps'] : [$data['reps']];
      }
    } else {
      $data['reps'] = ppt_resources_get_users_per_role($user);
      $data['reps'] = (is_array($data['reps'])) ? $data['reps'] : [$data['reps']];
    }
    // Get products belong to selected account.
    $account_info = node_load_multiple($data['accounts']);
    foreach ($account_info as $info) {
      $account_products_array = $info->field_products['und'];
      foreach ($account_products_array as $product) {
        $account_products_ids[] = $product['target_id'];
      }
    }
    // Get products belong to theraputic area.
    $thermatic_area_products_ids = get_thermatic_area_products_ids($data["therapeutic"]);
    // Get match products with account and thermatic area .
    if (!empty($thermatic_area_products_ids) && !empty($account_products_ids)) {
      foreach ($account_products_ids as $product_id) {
        if (in_array($product_id, $thermatic_area_products_ids)) {
          $data['products'][] = $product_id;
        }
      }
      if (!empty($data['products'])) {
        // Match current user products.
        if (is_rep($user)) {
          $final_products = [];
          $user_products = get_products_for_current_user($user_id, FALSE, FALSE);
          if (isset($user_products) && !empty($user_products)) {
            foreach ($user_products as $product_id) {
              if (in_array($product_id, $data['products'])) {
                $final_products[] = $product_id;
              }
            }
          }
          if (!empty($final_products)) {
            $data['products'] = $final_products;
          } else {
            return [];
          }
        }
      }
    } else {
      return [];
    }
    //    return $data['products'];
    if (empty($data['products'])) {
      return [];
    }

    // Planned orders.
    $orders = get_planned_orders($data['reps'], $data['accounts'], $data['products'], $date);
    if (isset($orders) && !empty($orders)) {
      foreach ($orders as $order) {
        // Load product.
        $product_id = $order->field_planned_product['und'][0]['target_id'];
        // Create array of product planned_orders .
        $expected_orders[$product_id]['planned_orders'][] = [
          'planned_period' => $order->field_planned_period['und'][0]['value'],
          'acutal_period' => $order->field_planned_actual_period['und'][0]['value'],
          'planned_quantity' => $order->field_planned_quantity['und'][0]['value'],
          'delivered_quantity' => $order->field_planned_delivered_quantity['und'][0]['value']
        ];
      }
    }
    if (isset($data['products']) && isset($data['accounts']) && isset($data['reps'])) {
      foreach ($data['accounts'] as $account) {
        foreach ($data['products'] as $product) {
          $entries = ppt_resources_get_entries($account, [$product], $data['reps']);
          $entries_records = get_entries_records_for_year($entries, $data['year'], 'consumption_stock_entry');
          if (isset($entries_records)) {
            foreach ($entries_records as $entry => $records) {
              $records_loaded = entity_load("entry_month_record", $records);
              foreach ($records_loaded as $record) {
                // Create array of product stocks .
                $expected_orders[$product]["stocks"][] = [
                  'consumption' => $record->field_consumption['und'][0]['value'],
                  'stocks' => $record->field_stocks['und'][0]['value'],
                  'entry_date' => $record->field_entry_date['und'][0]['value']
                ];
              }
            }
          }
        }
      }
    }
    $total_expected = [];
    if (isset($expected_orders)) {
      foreach ($expected_orders as $key => $orders) {
        // Intialize array with each month and values for each month = 0 .
        $final_array = [
          "Dec" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jan" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Feb" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Mar" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Apr" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "May" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jun" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jul" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Aug" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Sep" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Oct" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Nov" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ]
        ];
        if (isset($orders['planned_orders'])) {
          foreach ($orders['planned_orders'] as $order) {
            $final_array[date("M", strtotime($order['planned_period']))]['planned_quantity'] += $order['planned_quantity'];
            $final_array[date("M", strtotime($order['acutal_period']))]['delivered_quantity'] += $order['delivered_quantity'];
          }
        }
        if (isset($orders['stocks'])) {
          foreach ($orders['stocks'] as $order) {
            $final_array[date("M", strtotime($order['entry_date']))]['consumption'] += $order['consumption'];
            $final_array[date("M", strtotime($order['entry_date']))]['stocks'] += $order['stocks'];
          }
        }
        $product_name = taxonomy_term_load($key)->name;
        // Add final array to its product .
        $total_expected[$product_name] = $final_array;
      }
    }
    //  Set products matched with 0 values if not have values.
    foreach ($data['products'] as $product_id) {
      $product_name = taxonomy_term_load($product_id)->name;
      if (!in_array($product_name, array_keys($total_expected))) {
        $total_expected[$product_name] = [
          "Dec" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jan" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Feb" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Mar" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Apr" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "May" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jun" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Jul" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Aug" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Sep" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Oct" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ],
          "Nov" => [
            'stocks' => 0,
            'consumption' => 0,
            'planned_quantity' => 0,
            'delivered_quantity' => 0
          ]
        ];
      }
    }
    $quarter_array = [];
    switch ($data['quarter']) {
      case 1:
        foreach ($total_expected as $key => $product_arr) {
          $quarter_array[$key] = array_slice($product_arr, 0, 3);
        }
        break;
      case 2:
        foreach ($total_expected as $key => $product_arr) {
          $quarter_array[$key] = array_slice($product_arr, 3, 3);
        }
        break;
      case 3:
        foreach ($total_expected as $key => $product_arr) {
          $quarter_array[$key] = array_slice($product_arr, 6, 3);
        }
        break;
      case 4:
        foreach ($total_expected as $key => $product_arr) {
          $quarter_array[$key] = array_slice($product_arr, 9, 3);
        }
        break;
    }
    // Return YTD by current Month .
    foreach ($total_expected as $product_name => $months) {
      $counter = 0;
      $temp = [];
      $ytd = [
        "delivered_quantity" => 0,
        "consumption" => 0,
        "stocks" => 0 ,
        "moh" => 0
      ];
      $current_month = date('m');
      $current_year = date('Y');
      foreach ($months as $month => $total) {
        $nmonth = date('m', strtotime($month));
        // calculate Consumption avarage .
        if ($current_year == ($data['year']-1)){
          if ($current_month == 12) {
            // get the value of Dec only .
            if ($nmonth == $current_month) {
              $ytd['delivered_quantity'] += $total['delivered_quantity'];
              $ytd['consumption'] += $total['consumption'];
              $ytd['stocks'] += $total['stocks'];
            }
          }
        }
        else {
          // get months from 12 till months less than or equall current month .
          if ($nmonth <= $current_month || $nmonth == 12) {
            if( $total['consumption'] > 0){
              $counter+=1 ;
            }
            // Ytd DQ value.
            $ytd['delivered_quantity'] += $total['delivered_quantity'];
            $ytd['consumption'] += $total['consumption'];
//            $ytd['stocks'] += $total['stocks'];
          }
        }
        // Calculate latest available stock .
        if (empty($temp)) {
          $temp['value'] = (empty($total['stocks']))?0:$total['stocks'];
          $temp['month'] = ($nmonth == 12)?0:$nmonth ;
        }else{
          if (!empty($total['stocks']) && $nmonth > $temp['month'] ){
            $temp['value'] = $total['stocks'];
            $temp['month'] = $nmonth;
          }
        }
      }
      // Ytd stocks value .
      $ytd['stocks'] = $temp['value'];
      // Ytd consumption value.
      if ($counter!=0){
        $ytd['consumption'] =  number_format($ytd['consumption']/$counter,2,'.','')+0;
      }
      // Ytd moh vale.
      if ($ytd['consumption'] == 0){
        $ytd['moh'] = 0;
      }
      else {
        $moh_value = $ytd['stocks']/$ytd['consumption'] ;
        if (fmod($moh_value,1) !== 0.00) {
          $ytd['moh'] = number_format($moh_value,2,'.','') + 0;
        } else {
          $ytd['moh'] = $moh_value;
        }
      }
      $quarter_array[$product_name]['ytd'] = $ytd;
    }
    $ytd = array_column($quarter_array, 'ytd');
    $consumption = array_column($ytd, 'consumption');
    array_multisort($consumption, SORT_DESC, $quarter_array);
    return $quarter_array;
  }
}
/**
 * Get the next planned and delivered orders for current year.
 */
function ppt_resources_get_planned_delivered($data)
{
  $year = date('Y');
  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];
  if (isset($data['uid'])) {
    $uid = $data['uid'];
  } else {
    global $user;
    $uid = $user->uid;
  }
  $user = user_load($uid);
  if (isset($data['countries'])) {
    $countries = $data['countries'];
  } else {
    $countries = get_user_countries($user);
  }
  // Check if user selected accounts.
  if (isset($data['accounts'])) {
    $accounts = $data['accounts'];
  } else {
    $accounts = ppt_resources_get_role_accounts($user, $countries, FALSE);
  }
  $products = [];
  // Check if user selected products.
  if (isset($data['products'])) {
    $products = $data['products'];
  } else {
    // If the user is rep.
    if (is_rep($user)) {
      $products = get_products_for_current_user($uid, FALSE, FALSE);
    } else {
      $products = get_target_products_for_accounts($accounts);
    }
  }

  $nodes = get_planned_orders_for_acconuts_per_year($year, $accounts);

  // Initialze empty months.
  $months = array(
    "01" => 'December',
    "02" => 'January',
    "03" => 'February',
    "04" => 'March',
    "05" => 'April',
    "06" => 'May',
    "07" => 'June',
    "08" => 'July',
    "09" => 'August',
    "10" => 'September',
    "11" => 'October',
    "12" => 'November',
  );
  $final_arr = [];
  if (isset($nodes)) {
    // Consider a product exists with mutiple accounts.
    foreach ($nodes as $nid => $item) {
      $node = node_load($nid);
      $planned_product_tid = $node->field_planned_product["und"][0]["target_id"];
      if (in_array($planned_product_tid, $products)) {
        $planned_product = taxonomy_term_load($planned_product_tid);
        $planned_product_name = $planned_product->name;
        // Get node values for product (planned and delivered).
        if (isset($node->field_planned_period["und"])) {
          $node_date = $node->field_planned_period["und"][0]['value'];
          $planned_month = date("F", strtotime($node_date));
        }
        $planned_quantity = 0;
        if (isset($node->field_planned_quantity["und"])) {
          $planned_quantity = $node->field_planned_quantity["und"][0]["value"];
        }
        if (isset($node->field_planned_actual_period["und"])) {
          $node_date = $node->field_planned_actual_period["und"][0]['value'];
          $delivery_month = date("F", strtotime($node_date));
        }
        $delivered_quantity = 0;
        if (isset($node->field_planned_delivered_quantity["und"])) {
          $delivered_quantity = $node->field_planned_delivered_quantity["und"][0]["value"];
        }
        // If product already exists, update its values for node months.
        if (isset($final_arr[$planned_product_name])) {
          if (isset($final_arr[$planned_product_name]["Planned"][$planned_month])) {
            $final_arr[$planned_product_name]["Planned"][$planned_month][0] += (int) $planned_quantity;
          } else {
            $final_arr[$planned_product_name]["Planned"][$planned_month][0] = [(int) $planned_quantity];
          }
          if (isset($final_arr[$planned_product_name]["Actual"][$delivery_month])) {
            $final_arr[$planned_product_name]["Actual"][$delivery_month][0] += (int) $delivered_quantity;
          } else {
            $final_arr[$planned_product_name]["Actual"][$delivery_month] = [(int) $delivered_quantity];
          }
        } else {
          // Initialze product array with 0 for all months, then update it with current node data.
          $final_arr[$planned_product_name] = ["Actual" => [], "Planned" => []];
          for ($i = 1; $i <= 12; $i++) {
            $month = $months[sprintf('%02d', $i)];
            $final_arr[$planned_product_name]["Actual"][$month] = [0];
            $final_arr[$planned_product_name]["Planned"][$month] = [0];
          }
          $final_arr[$planned_product_name]["Actual"][$delivery_month] = [(int) $delivered_quantity];
          $final_arr[$planned_product_name]["Planned"][$planned_month] = [(int) $planned_quantity];
        }
      }
    }
  }
  // [product => [actual => [months], target => [months]]]
  return $final_arr;
}


/**
 * Get the delivered planned orders per account and product.
 */
function ppt_resources_get_delivered_planned_orders($data)
{
  global $user;
  $months = array(
    "01" => 'December',
    "02" => 'January',
    "03" => 'February',
    "04" => 'March',
    "05" => 'April',
    "06" => 'May',
    "07" => 'June',
    "08" => 'July',
    "09" => 'August',
    "10" => 'September',
    "11" => 'October',
    "12" => 'November',
  );

  if (!isset($data['year'])) {
    return services_error('Year is not defined!', 500);
  }

  if (empty($data['accounts'])) {
    return services_error('Accounts is not defined!', 500);
  }

  if (empty($data['products'])) {
    return services_error('Products is not defined!', 500);
  }

  $year = $data['year'];
  $accounts = $data['accounts'];
  $products = $data['products'];
  $dates = get_year_dates($year);
  $start_date = $dates['start_date'];
  $end_date = $dates['end_date'];

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'planned_order')
    ->fieldCondition('field_planned_account', 'target_id', $accounts, 'IN')
    ->fieldCondition('field_planned_product', 'target_id', $products, 'IN')
    ->fieldCondition('field_planned_actual_period', 'value', $start_date, '>=')
    ->fieldCondition('field_planned_actual_period', 'value', $end_date, '<=')
    ->addMetaData('account', user_load(1));

  $records = $query->execute();
  $final_arr = [];

  if (isset($records['node'])) {
    $nodes_ids = array_keys($records['node']);
    $nodes = node_load_multiple($nodes_ids);

    foreach ($nodes as $node) {
      // Get node planned product name.
      $planned_product_tid = $node->field_planned_product['und'][0]['target_id'];
      $planned_product = taxonomy_term_load($planned_product_tid);
      $planned_product_name = $planned_product->name;

      // Get node date for product (planned).
      if (isset($node->field_planned_actual_period['und'])) {
        $node_date = $node->field_planned_actual_period['und'][0]['value'];
        $delivered_month = date("F", strtotime($node_date));
      }

      // Get node values for planned quantity.
      $delivered_quantity = 0;
      if (isset($node->field_planned_delivered_quantity['und'])) {
        $delivered_quantity = $node->field_planned_delivered_quantity['und'][0]['value'];
      }

      // If product already exists, update its values for node months.
      if (isset($final_arr['delivered'][$planned_product_name])) {
        if (isset($final_arr['delivered'][$planned_product_name][$delivered_month])) {
          $final_arr['delivered'][$planned_product_name][$delivered_month][0] += (int) $delivered_quantity;
        } else {
          $final_arr['delivered'][$planned_product_name][$delivered_month][0] = [(int) $delivered_quantity];
        }
      } else {
        // Initialze product array with 0 for all months, then update it with current node data.
        $final_arr['delivered'][$planned_product_name] = [];
        for ($i = 1; $i <= 12; $i++) {
          $month = $months[sprintf('%02d', $i)];
          $final_arr['delivered'][$planned_product_name][$month] = [0];
        }
        $final_arr['delivered'][$planned_product_name][$delivered_month] = [(int) $delivered_quantity];
      }
    }
  }
  return $final_arr;
}

/**
 * Get start date and end date.
 */
function get_year_dates($year = null, $start_month = 12, $end_month = 11)
{
  if (!isset($year)) {
    $year = date('Y');
  }
  $start_date = $year - 1 . '-' . $start_month . '-01';
  $end_date = $year . '-' . $end_month . '-30';
  return [
    'start_date' => $start_date,
    'end_date' => $end_date
  ];
}

/**
 * Get Teams accounts.
 */
function ppt_resources_get_team_accounts($data)
{
  $accounts = [];
  if (isset($data['team'])) {
    $reps = node_load($data['team'])->field_reps['und'];
    if (isset($reps)) {
      foreach ($reps as $rep) {
        $reps_accounts = get_accounts_for_current_user($rep['target_id'], FALSE);
        $accounts = array_merge($accounts, $reps_accounts);
      }
    }
  }
  $account_arr = [];
  $uniqe_arr = array_unique($accounts);
  foreach ($uniqe_arr as $account) {
    $name = node_load($account)->title;
    $account_arr[$account] = [
      "id" => $account,
      "name" => $name
    ];
  }
  return $account_arr;
}

/**
 * Get teams reps.
 */
function ppt_resources_get_team_reps($data)
{
  $rep_arr = [];
  if (isset($data['team'])) {
    if (is_array($data['team'])) {
      $data['team'] = $data['team'][0];
    }
    $reps = node_load($data['team'])->field_reps['und'];
    if (isset($reps)) {
      foreach ($reps as $rep) {
        $name = user_load($rep['target_id'])->field_full_name['und'][0]['value'];
        $username = user_load($rep['target_id'])->name;
        $rep_arr[$rep['target_id']] = [
          "id" => $rep['target_id'],
          "name" => $name,
          "username" => $username
        ];
      }
    }
  }
  return $rep_arr;
}

/**
 * Get teams products.
 */
function ppt_resources_get_team_account_products($data)
{
  $accounts = ppt_resources_get_team_accounts($data);
  $data['accounts'] = array_keys($accounts);
  $products = ppt_resources_get_target_accounts_products($data);
  return $products;
}
