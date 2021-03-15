<?php

/**
 * @file
 * Custom template file.
 */
 ?>

<div id="report-wrapper" class="hidden-table">
    <canvas id="canvas"></canvas>
    <table id="table"></table>
</div>

<div class="row reports-container-row">
    <div class="reports-container" id="cot-<?php print $filter;?>s-container" class="col-xs-12">
        <div id="cot-<?php print $filter; ?>s-report"></div>
        <div class="buttons hidden" data-html2canvas-ignore="true">
            <button class="btn btn-primary btn-pdf" data-selector="cot-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-img" data-selector="cot-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-csv" data-selector="cot-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
        </div>
    </div>
    <div class="reports-container" id="npr-<?php print $filter;?>s-container" class="col-xs-12">
        <div id="npr-<?php print $filter; ?>s-report"></div>
        <div class="buttons hidden" data-html2canvas-ignore="true">
            <button class="btn btn-primary btn-pdf" data-selector="npr-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-img" data-selector="npr-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-csv" data-selector="npr-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
        </div>
    </div>
    <div class="reports-container" id="drop-<?php print $filter;?>s-container" class="col-xs-12">
        <div id="drop-<?php print $filter; ?>s-report"></div>
        <div class="buttons hidden" data-html2canvas-ignore="true">
            <button class="btn btn-primary btn-pdf" data-selector="drop-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-img" data-selector="drop-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
            <button class="btn btn-primary btn-csv" data-selector="drop-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
        </div>
    </div>
    <?php if ($filter == "product") :?>
        <div class="reports-container" id="stocks-<?php print $filter;?>s-container" class="col-xs-12">
            <div id="stocks-<?php print $filter; ?>s-report"></div>
            <div class="buttons hidden" data-html2canvas-ignore="true">
                <button class="btn btn-primary btn-pdf" data-selector="stocks-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-img" data-selector="stocks-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-csv" data-selector="stocks-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
            </div>
        </div>
        <div class="reports-container" id="consumption-<?php print $filter;?>s-container" class="col-xs-12">
            <div id="consumption-<?php print $filter; ?>s-report"></div>
            <div class="buttons hidden" data-html2canvas-ignore="true">
                <button class="btn btn-primary btn-pdf" data-selector="consumption-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-img" data-selector="consumption-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-csv" data-selector="consumption-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
            </div>
        </div>
        <div class="reports-container" id="usd-<?php print $filter;?>s-container" class="col-xs-12">
            <div id="usd-<?php print $filter; ?>s-report"></div>
            <div class="buttons hidden" data-html2canvas-ignore="true">
                <button class="btn btn-primary btn-pdf" data-selector="usd-<?php print $filter;?>s-container" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-img" data-selector="usd-<?php print $filter;?>s-container" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>
                <button class="btn btn-primary btn-csv" data-selector="usd-<?php print $filter;?>s-container" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>
            </div>
        </div>
    <?php endif; ?>
</div>
