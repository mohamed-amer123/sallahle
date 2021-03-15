<?php

/**
 * @file
 * Custom template file.
 */

$filter = "product"; ?>

<?php global $user;?>
<!-- Filters Sections -->
<section id="dashboard-filters target-delivered">

  <?php
  drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/multiple-select.js');
  drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/select2.min.js');
  drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/multiple-select.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/select2.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  ?>
  <?php if(is_comm_lead($user)):
    $data=get_comm_lead_country_info($user->uid);
  ?>
  <input type="hidden" name="come_lead" id="comm_lead_role" value="come_lead">
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
        <div class="col-md-3 dashboard-filter">
          <div class="form-group" id="cluster-selection">
            <label for="clusters-filter">Clusters*</label>
            <select class="form-control" id="clusters-filter" required disabled multiple data-resource="get_user_countries_per_cluster" data-target="countries-filter" multiple="multiple">

            </select>
          </div>
        </div>

        <!-- Country Filter -->
        <div class="col-md-3 dashboard-filter">
          <div class="form-group" id="countries-selection">
            <label for="countries-filter">Country*</label>

            <select class="form-control" data-placeholder="Select country(s)" id="countries-filter"  required disabled multiple  multiple="multiple">
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

      </div>
      <div>

        <!-- Account Filter -->
        <div class="col-md-4 dashboard-filter">
          <div class="form-group">
            <label for="accounts-filter">Account*</label>
            <select class="form-control chosen-select" data-placeholder="Select account(s)" id="accounts-filter" disabled required >
            </select>
          </div>
        </div>

        <!-- Reps Filter -->
        <div class="col-md-3 dashboard-filter">
          <div class="form-group">
            <label for="reps-filter">Reps*</label>
            <select class="form-control" id="reps-filter" disabled multiple>

            </select>
          </div>
        </div>

        <!--    therapeutic area-->
        <div class="col-md-4 dashboard-filter">
          <div class="form-group">
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
      </div>
      <div>
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

        <div class="col-md-2 dashboard-filter dashboard-filter-buttons" id="target-delivered-submit">
          <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
          <button id="reset-button" class="btn btn-default">Reset</button>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if(!is_comm_lead($user)) :?>
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
      <div class="col-md-3 dashboard-filter">
        <div class="form-group" id="cluster-selection">
          <label for="clusters-filter">Clusters*</label>
          <select class="form-control" id="clusters-filter" required disabled multiple data-resource="get_user_countries_per_cluster" data-target="countries-filter" multiple="multiple">

          </select>
        </div>
      </div>

      <!-- Country Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group" id="countries-selection">
          <label for="countries-filter">Country*</label>

          <select class="form-control" data-placeholder="Select country(s)" id="countries-filter"  required disabled multiple data-resource="get_accounts_per_countries" data-target="accounts-filter" multiple="multiple">
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

      <!-- Account Filter -->
      <div class="col-md-5 dashboard-filter">
        <div class="form-group">
          <label for="accounts-filter">Account*</label>
          <select class="form-control chosen-select" data-placeholder="Select account(s)" id="accounts-filter" disabled required data-resource="get_reps_of_accounts_country" data-target="reps-filter" multiple="multiple">
          </select>
        </div>
      </div>

      <!-- Reps Filter -->
      <div class="col-md-3 dashboard-filter">
        <div class="form-group">
          <label for="reps-filter">Reps*</label>
          <select class="form-control" id="reps-filter" disabled multiple required>

          </select>
        </div>
      </div>

<!--    therapeutic area-->
      <div class="col-md-4 dashboard-filter">
        <div class="form-group">
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

      <div class="col-md-2 dashboard-filter dashboard-filter-buttons" id="target-delivered-submit">
        <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
        <button id="reset-button" class="btn btn-default">Reset</button>
      </div>
    </div>
  </div>
  <?php endif; ?>
</section>
<div class="reports-container-row">
  <div class="row">
    <div class="col-md-1">
      <div class="buttons-table text-center" id="target-delivered-table-buttons">
        <button class="btn btn-primary btn-img" data-selector="target-delivered-table" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
        <button class="btn btn-primary btn-csv" data-selector="target-delivered-table" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
      </div>
    </div>
    <div class="col-md-11" id="target-delivered-report">
      <div id="target-delivered-table"></div>
    </div>
  </div>
</div>
<script>
  jQuery('#accounts-filter').select2();
</script>
