<?php

/**
 * @file
 * Custom template file.
 */

$filter = "product"; ?>


<!-- Filters Sections -->
<section id="dashboard-filters">

<?php
drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/multiple-select.js');
drupal_add_js(drupal_get_path('module', 'ppt_dashboard') . '/js/select2.min.js');
drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/multiple-select.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
drupal_add_css(drupal_get_path('module', 'ppt_dashboard') . '/css/select2.min.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
?>
  <?php global $user;?>
  <?php if(is_comm_lead($user)):?>

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

            <select class="form-control" data-placeholder="Select country(s)" id="countries-filter"  required disabled  multiple="multiple">
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
        <div class="col-md-4 dashboard-filter">

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
    </div>
    <div class="row form-row">
      <div>
        <!-- Account Filter -->
        <div class="col-md-5 dashboard-filter">
          <div class="form-group" id="accounts-selection">
            <label for="accounts-filter">Account*</label>
            <select class="form-control chosen-select" data-placeholder="Select account(s)" id="accounts-filter" disabled required multiple="multiple" data-resource="get_target_accounts_products" data-target="products-filter">
            </select>
          </div>
        </div>
        <!-- Reps Filter -->
        <div class="col-md-3 dashboard-filter">
          <div class="form-group">
            <label for="reps-filter">Reps</label>
            <select class="form-control" id="reps-filter" disabled multiple>

            </select>
          </div>
        </div>

        <?php if ($filter == "product"): ?>
          <!-- Products Filter -->

          <div class="col-md-4 dashboard-filter">
            <div class="form-group" id="products-selection">
              <label for="products-filter">Products</label>
              <select class="form-control" id="products-filter" disabled multiple>

              </select>
            </div>
          </div>
        <?php endif; ?>


      </div>
    </div>
  <div class="row form-row">
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
      <!-- Month Filter -->
      <div class="col-md-2 dashboard-filter">
        <div class="form-group">
          <label for="month-filter">Month</label>
          <select class="form-control" id="month-filter">
            <option value=''>- None -</option>
            <?php
            for ($i = 1; $i <= 12; $i++) {
              print "<option value='$i'>$i</option>";
            }
            ?>
          </select>
        </div>
      </div>
    </div>
  </div>
  <?php endif;?>
  <?php if (!is_comm_lead($user)):?>
<div class="row form-row">
    <div>
        <!-- Region Filter -->
        <div class="col-md-1 dashboard-filter">
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

        <!-- Country Filter -->
        <div class="col-md-2 dashboard-filter">
            <div class="form-group" id="countries-selection">
            <label for="countries-filter">Country*</label>

            <select class="form-control" data-placeholder="Select country(s)" id="countries-filter"  required disabled multiple data-resource="get_accounts_per_countries" data-target="accounts-filter" multiple="multiple">
            </select>
        <script>


    </script>
            </div>
        </div>

        <!-- Account Filter -->
        <div class="col-md-7 dashboard-filter">
            <div class="form-group" id="accounts-selection">
            <label for="accounts-filter">Account*</label>
            <select class="form-control chosen-select" data-placeholder="Select account(s)" id="accounts-filter" disabled required multiple data-resource="get_reps_of_accounts_country,get_target_accounts_products,get_accounts_indications" data-target="reps-filter,products-filter,indications-filter">
            </select>
            </div>
        </div>
    </div>
</div>
<div class="row form-row">
    <div>
        <!-- Reps Filter -->
        <div class="col-md-3 dashboard-filter">
            <div class="form-group">
            <label for="reps-filter">Reps</label>
            <select class="form-control" id="reps-filter" disabled multiple>

            </select>
            </div>
        </div>

        <?php if ($filter == "product"): ?>
            <!-- Products Filter -->

            <div class="col-md-7 dashboard-filter">
                <div class="form-group" id="products-selection">
                <label for="products-filter">Products</label>
                <select class="form-control" id="products-filter" disabled multiple>

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
        <!-- Month Filter -->
        <div class="col-md-1 dashboard-filter">
            <div class="form-group">
            <label for="month-filter">Month</label>
            <select class="form-control" id="month-filter">
                <option value=''>- None -</option>
                <?php
                    for ($i = 1; $i <= 12; $i++) {
                        print "<option value='$i'>$i</option>";
                    }
                ?>
            </select>
            </div>
        </div>
    </div>
</div>
  <?php endif; ?>
  <div class="row form-row">
    <div>
        <div class="col-md-2 dashboard-filter dashboard-filter-buttons">
            <button id="dashboard-submit" class="btn btn-primary" disabled>Apply</button>
            <button id="reset-button" class="btn btn-default">Reset</button>
        </div>
    </div>
  </div>
</section>

<div id="report-wrapper" class="hidden-table">
    <canvas id="canvas"></canvas>
    <table id="table"></table>
</div>

<div class="row reports-container-row">
    <div class="col-md-3 reports-container" id="cot-<?php print $filter;?>s-container">
        <div id="cot-<?php print $filter; ?>s-report"></div>
    </div>
    <div class="col-md-3 reports-container" id="npr-<?php print $filter;?>s-container">
        <div id="npr-<?php print $filter; ?>s-report"></div>
    </div>

    <div class="col-md-3 reports-container" id="target-cot-target-<?php print $filter;?>s-container">
        <div id="target-cot-target-<?php print $filter; ?>s-report"></div>
    </div>
    <div class="col-md-3 reports-container" id="target-npr-target-<?php print $filter;?>s-container">
        <div id="target-npr-target-<?php print $filter; ?>s-report"></div>
    </div>

    <div class="col-md-3 reports-container" id="cot-pie-indications-container">
        <div id="cot-pie-indications-report"></div>
        <div class="buttons hidden" data-html2canvas-ignore="true">
            <button class="btn btn-primary btn-pdf" data-selector="cot-pie-indications-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-img" data-selector="cot-pie-indications-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-csv" data-selector="cot-pie-indications-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
        </div>
    </div>
    <div class="col-md-3 reports-container" id="npr-pie-indications-container">
        <div id="npr-pie-indications-report"></div>
        <div class="buttons hidden" data-html2canvas-ignore="true">
            <button class="btn btn-primary btn-pdf" data-selector="npr-pie-indications-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-img" data-selector="npr-pie-indications-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-csv" data-selector="npr-pie-indications-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
        </div>
    </div>

    <div class="col-md-6 reports-container" id="usd-<?php print $filter;?>s-container">
        <div id="usd-<?php print $filter; ?>s-report"></div>
    </div>
</div>
