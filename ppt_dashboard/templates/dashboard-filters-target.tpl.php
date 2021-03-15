<?php

/**
 * @file
 * Kpr(ppt_dashboard_get_filters_arraies());.
 */
drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/multiple-select.js');
drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/select2.min.js');
drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/multiple-select.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/select2.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
?>

<div>
  <?php global $user; ?>
  <?php if (is_comm_lead($user)) : ?>
    <div id="report-form">
      <div class="row form-row">
        <div>
          <!-- Region Filter -->
          <div class="col-md-2 dashboard-filter">
            <div class="form-group">
              <label for="region-filter">Region*</label>
              <select class="form-control" id="region-filter" required required data-resource="get_user_clusters" data-target="clusters-filter">
                <option value="">Select a region*</option>
                <?php
                // Get all regions terms.
                $vocabulary = taxonomy_vocabulary_machine_name_load('region');
                $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
                if (empty($terms)) {
                  $terms = array();
                }
                foreach ($terms as $term) {
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
              <select class="form-control" id="clusters-filter" disabled required multiple data-resource="get_user_countries_per_cluster" data-target="countries-filter" multiple="multiple">

              </select>
            </div>
          </div>

          <!-- Country Filter -->
          <div class="col-md-3 dashboard-filter">
            <div class="form-group" id="countries-selection">
              <label for="country-filter">Countries*</label>
              <select class="form-control" data-placeholder="Select country(s)" id="countries-filter" required disabled multiple ?>">
              </select>
              <script>
                jQuery(document).on('click', '#clusters-filter', function() {
                  jQuery("#countries-filter").multipleSelect({
                    placeholder: "Select country(s)"
                  });
                })
              </script>
            </div>
          </div>

          <?php if (in_array('country', $filters)) {
            $data_target = "products-filter";
            $data_resource = "get_team_account_products";
          } else {
            $data_target = "";
            $data_resource = "";
          } ?>
          <!-- Teams Filter -->
          <div class="col-md-4 dashboard-filter">
            <div class="form-group">
              <label for="teams-filter">Teams*</label>
              <select class="form-control" id="team-filter" required data-resource="get_team_accounts,get_team_reps,<?php print $data_resource; ?>" data-target="accounts-filter,reps-filter,<?php print $data_target; ?>">
                <option value="">Select a Team*</option>
                <?php
                $teams = ppt_resources_get_comm_lead_teams($user->uid);
                foreach ($teams as $team) {
                  print  "<option value=" . $team['id'] . ">" . $team['name'] . "</option>";
                }
                ?>
              </select>
            </div>
          </div>
        </div>
      </div>

      <div class="row form-row">
        <div>
          <?php if (in_array("account", $filters)) : ?>
            <!-- Accounts Filter -->
            <div class="col-md-4 dashboard-filter">
              <div class="form-group" id="accounts-selection">
                <label for="account-filter">Accounts*</label>
                <select class="form-control" id="accounts-filter" required disabled multiple data-resource="get_target_accounts_products" data-target="products-filter">
                </select>
              </div>
            </div>
          <?php endif; ?>

          <?php if (in_array("rep", $filters)) : ?>
            <!-- Reps Filter -->
            <div class="col-md-4 dashboard-filter">
              <div class="form-group">
                <label for="rep-filter">Reps</label>
                <select class="form-control" id="reps-filter" data-resource="get_target_accounts_products" data-target="products-filter" required disabled multiple>
                </select>
              </div>
            </div>
          <?php endif; ?>


          <?php if (in_array("product", $filters)) : ?>
            <!-- Products Filter -->
            <div class="col-md-4 dashboard-filter">
              <div class="form-group" id="products-selection">
                <label for="product-filter">Products</label>
                <select class="form-control" id="products-filter" required disabled multiple>
                </select>
              </div>
            </div>
          <?php endif; ?>
        </div>
      </div>

      <div class="row form-row">
        <!-- Year Filter -->
        <div class="col-md-3 dashboard-filter">
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
        <div class="col-md-2 dashboard-filter dashboard-filter-buttons">
          <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
          <button id="reset-button" class="btn btn-default">Reset</button>
        </div>
      </div>
    </div>


  <?php endif; ?>

  <?php if (!is_comm_lead($user)) : ?>
    <div id="report-form">
      <!-- Region Filter -->
      <div class="col-md-1 dashboard-filter">
        <div class="form-group">
          <label for="region-filter">Region*</label>
          <select class="form-control" id="region-filter" required required data-resource="get_user_clusters" data-target="clusters-filter">
            <option value="">Select a region*</option>
            <?php
            // Get all regions terms.
            $vocabulary = taxonomy_vocabulary_machine_name_load('region');
            $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
            if (empty($terms)) {
              $terms = array();
            }
            foreach ($terms as $term) {
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
          <select class="form-control" id="clusters-filter" disabled required multiple data-resource="get_user_countries_per_cluster" data-target="countries-filter" multiple="multiple">

          </select>
        </div>
      </div>

      <?php
      if (in_array("account", $filters)) {
        $data_resource = "get_accounts_per_countries";
        $data_target = "accounts-filter";
      } else {
        $data_resource = "get_target_accounts_products";
        $data_target = "products-filter";
      }

      ?>
      <!-- Country Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group" id="countries-selection">
          <label for="country-filter">Countries*</label>
          <select class="form-control" data-placeholder="Select country(s)" id="countries-filter" required disabled multiple data-resource="<?php print $data_resource; ?>" data-target="<?php print $data_target; ?>">
          </select>
          <script>
          </script>
        </div>
      </div>

      <?php if (in_array("account", $filters)) : ?>
        <!-- Accounts Filter -->
        <div class="col-md-7 dashboard-filter">
          <div class="form-group" id="accounts-selection">
            <label for="account-filter">Accounts*</label>
            <select class="form-control" id="accounts-filter" required disabled multiple data-resource="get_reps_of_accounts_country,get_target_accounts_products" data-target="reps-filter,products-filter">
            </select>
          </div>
        </div>
      <?php endif; ?>

      <?php if (in_array("rep", $filters)) : ?>
        <!-- Products Filter -->
        <div class="col-md-2 dashboard-filter">
          <div class="form-group">
            <label for="rep-filter">Reps</label>
            <select class="form-control" id="reps-filter" data-resource="get_target_accounts_products" data-target="products-filter" required disabled multiple>
            </select>
          </div>
        </div>
      <?php endif; ?>

      <?php if (in_array("product", $filters)) : ?>
        <!-- Products Filter -->
        <div class="col-md-7 dashboard-filter">
          <div class="form-group" id="products-selection">
            <label for="product-filter">Products</label>
            <select class="form-control" id="products-filter" required disabled multiple>
            </select>
          </div>
        </div>
      <?php endif; ?>

      <!-- Year Filter -->
      <div class="col-md-1 dashboard-filter">
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
      <div class="col-md-2 dashboard-filter dashboard-filter-buttons">
        <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
        <button id="reset-button" class="btn btn-default">Reset</button>
      </div>
    </div>
  <?php endif; ?>
  <div class="row form-row">
    <!-- Chart Type Filter -->
    <div class="col-md-2 dashboard-filter" id="chart-type-filter">
      <div class="form-group">
        <label for="chart-type-filter">Chart Type</label>
        <button class="change-chart-type btn btn-info selected" value="AreaChart" disabled><i class="fa fa-area-chart" aria-hidden="true"></i> Area Chart</button>
        <button class="change-chart-type btn btn-info" value="LineChart" disabled><i class="fa fa-line-chart" aria-hidden="true"></i> Line Chart</button>
        <button class="change-chart-type btn btn-info" value="ComboChart" disabled><i class="fa fa-bar-chart" aria-hidden="true"></i> Combo Chart</button>
      </div>
    </div>
  </div>
</div>