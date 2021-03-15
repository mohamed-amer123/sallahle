<?php

/**
 * @file
 * Custom template file.
 */

$filter = "product"; ?>


<!-- Filters Sections -->
<section id="dashboard-filters expected-orders">

  <?php
  drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/multiple-select.js');
  drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/select2.min.js');
  drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/multiple-select.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/select2.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  ?>
  <?php global $user?>
  <div class="row form-row">
    <div>
      <!-- Region Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group">
          <label for="region-filter">Region*</label>
          <select class="form-control" id="region-filter" required data-resource="get_user_clusters" data-target="clusters-filter">
            <option value="">Select a region*</option>
            <?php
            // Get all regions terms.
            $vocabulary = taxonomy_vocabulary_machine_name_load('region');
            $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
            if(empty($terms)){
              $terms = array();
            }
            foreach($terms as $term) {
              print "<option value='$term->tid'>$term->name</option>";
            }
            ?>
          </select>
        </div>
      </div>


      <!-- Cluster Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group" id="cluster-selection">
          <label for="clusters-filter">Clusters*</label>
          <select class="form-control" id="clusters-filter" required disabled multiple data-resource="get_user_countries_per_cluster" data-target="countries-filter" multiple="multiple">

          </select>
        </div>
      </div>

      <?php
        if (!is_comm_lead($user)) {
          $data_resource = "get_accounts_per_countries";
          $data_target = "accounts-filter";
        } else {
          $data_resource = "";
          $data_target = "";
        }

      ?>

      <!-- Country Filter -->
      <div class="col-md-3 dashboard-filter">
        <div class="form-group" id="countries-selection">
          <label for="countries-filter">Country*</label>

          <select class="form-control" data-placeholder="Select country(s)" id="countries-filter"  required disabled multiple data-resource="<?php print $data_resource; ?>" data-target="<?php print $data_target; ?>" >
          </select>
          <script>
            jQuery(document).on('click','#clusters-filter', function(){
              jQuery("#countries-filter").multipleSelect({
                placeholder: "Select country(s)"
              });
            })

          </script>
        </div>
      </div>
      <?php if(is_comm_lead($user)):?>
        <!-- Teams Filter -->
        <div class="col-md-3 dashboard-filter">
          <div class="form-group">
            <label for="teams-filter">Teams*</label>
            <select class="form-control" id="team-filter" required data-resource="get_team_accounts,get_team_reps" data-target="accounts-filter,reps-filter">
              <option value="">Select a Team*</option>
              <?php
              $teams = ppt_resources_get_comm_lead_teams($user->uid);
              foreach ($teams as $team){
                print  "<option value=" . $team['id'] . ">" . $team['name'] . "</option>";
              }
              ?>
            </select>
          </div>
        </div>
      <?php endif;?>

      <!-- Account Filter -->
      <div class="col-md-3 dashboard-filter">
        <div class="form-group">
          <label for="accounts-filter">Account*</label>
          <select class="form-control chosen-select" data-placeholder="Select account(s)" id="accounts-filter" disabled required >
          </select>
        </div>
      </div>
      <!--therapeutic area-->
      <div class="col-md-4 dashboard-filter">
        <div class="form-group" >
          <label for="therapeutic-filter">Therapeutic Area*</label>
          <select class="form-control" id="therapeutic-filter" required>
            <option value="">Select a Therapeutic Area*</option>
            <?php
            $view_name = 'therapeutic_area_filter';
            $display_name = 'filter';
            $view = views_get_view($view_name);
            $view->set_display($display_name);
            $view->is_cacheable = FALSE;
            $view->pre_execute();
            $view->execute();
            foreach ($view->result as $result){
              print  "<option value='$result->tid'> $result->taxonomy_term_data_name </option>";
            }
            ?>
          </select>
        </div>
      </div>

      <!-- Year Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group">
          <label for="year-filter">Year*</label>
          <select class="form-control" id="year-filter" required>
            <?php
            for ($i = date('Y'); $i >= date('Y') - 5; $i--) {
              print "<option value='$i'>$i</option>";
            }
            ?>
          </select>
        </div>
      </div>

      <!-- quarter filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group">
          <label for="quarter-filter">Quarter*</label>
          <select class="form-control chosen-select" data-placeholder="Select Quarter(s)" id="quarter-filter"  required >
            <option value="">select quarter*</option>
            <option value="1">1</option>
            <option value="2">2</option>
            <option value="3">3</option>
            <option value="4">4</option>
          </select>
        </div>
      </div>
      <div class="col-md-2 dashboard-filter dashboard-filter-buttons" id="target-delivered-submit">
        <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
        <button id="reset-button" class="btn btn-default">Reset</button>
      </div>
    </div>
  </div>
</section>
<div class="reports-container-row">
  <div class="row">
    <div class="col-md-1">
      <div class="buttons-table text-center" id="target-delivered-table-buttons">
        <button class="btn btn-primary btn-img" data-selector="expected-orders-table" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
        <button class="btn btn-primary btn-csv" data-selector="expected-orders-table" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
      </div>
    </div>
    <div class="col-md-11" id="expected-orders-report">
      <dev id="expected-orders-error-msg"></dev>
      <div id="expected-orders-table">
        <table class="table table-bordered text-center">
          <thead id="expected-table-header" >
            <tr id="expected-table-tr" class="text_center">
            </tr>
            <tr id="month-header">
            </tr>
          </thead>
          <tbody id="expected-table-body">
          </tbody>
        </table>
      </div>
    </div>
  </div>
</div>
<script>
  jQuery('#accounts-filter').select2();
</script>
