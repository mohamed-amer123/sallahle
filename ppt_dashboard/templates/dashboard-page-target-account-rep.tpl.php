<?php

/**
 * @file
 * Custom template file.
 */


$filters = array("account", "rep", "product"); ?>

<!-- Filters Sections -->
<section id="dashboard-filters">
    <?php include_once 'dashboard-filters-target.tpl.php'; ?>
</section>

<!-- Filters Sections -->
<section id="dashboard-charts">
<?php include_once 'dashboard-charts-target.tpl.php'; ?>
</section>
