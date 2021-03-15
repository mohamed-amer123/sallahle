(function ($) {
  Drupal.behaviors.ppt_dashboard = {
    attach: function (context, settings) {
      if (!settings.ppt_dashboard || !google.charts) {
        return;
      }
      function setToken() {
        $.get('/services/session/token').done(function (data) {
          settings.ppt_dashboard.token = data;
          pageReady(settings);
        });
      }
      if ($("body").hasClass("logged-in")) {
        setToken();
      }
    }
  };
  var requestsNumber = 0;
  var settings;
  var chartOptions = {
    vAxis: {
      minValue: 0,
      textPosition: 'out'
    },
    titlePosition: 'out',
    axisTitlesPosition: 'in',
    chartArea: {
      width: "75%"
    },
    animation: {
      duration: 2000,
      startup: true,
      easing: 'out'
    },
    is3D: true,
    colors: ['#ec2c3d', '#4751b1', '#54b258', '#f7932b', '#e10064', '#4198ee', '#8dc456', '#f64730', '#384046', '#3babef', '#cadc4f', '#77534a', '#9a16ac', '#38bed1', '#faea55', '#9e9e9e', '#6937b3', '#269888', '#f9be36', '#637e8a']
  };
  var chartType = "AreaChart";
  function pageReady(drupalSettings) {
    // save settings and init google chart
    settings = drupalSettings;
    google.charts.load('current', {
      'packages': ['corechart']
    });
    initUrlFilters();

    addFiltersListener();

    window.onpopstate = function () {
      handleUrlFilters();
    };

    $("#dashboard-submit").on("click", function () {
      if (validForm()) {
        clickSubmit();
      }
    });
    $("#reset-button").on("click", function () {
      //$(this).closest('.form-row').find("input[type=text], textarea, select").val("");
      $('.form-row').find("input[type=text], textarea, select").val("");
      var href = window.location.href;
      var hrefFrags = href.split("?");
      window.history.pushState('', '', hrefFrags[0]);
      handleUrlFilters();
    });
    $("#chart-type-filter button").click(function () {
      if (chartType == this.value) {
        return;
      }
      chartType = this.value;
      $('#chart-type-filter button').removeClass('selected');
      $(this).addClass('selected');
      if (chartType == "ComboChart") {
        chartOptions.seriesType = 'bars';
      } else {
        delete chartOptions.seriesType;
      }
      if (validForm()) {
        clickSubmit();
      }
    });

    handleExportDataAsFile();
    handleTableDataASFile();


    if (settings.ppt_dashboard.resource == "front") {
      clickSubmit();
    }

  }

  function initUrlFilters(selector) {
    var href = window.location.href;
    if (!selector) {
      var hrefFrags = href.split("?");
      if (!hrefFrags[1]) {
        var now = new Date();
        setFilter(now.getFullYear(), $("year-filter"), "year");
        return;
      }
      if (!searchParams_get("region")) {
        return;
      }
      selector = "region-filter";
      year = searchParams_get("year");
      $("#year-filter").val(year);
    }
    var filter = selector.split("-")[0];
    value = searchParams_get(filter);
    if (value && $("#" + selector).prop("multiple")) {
      value = value.split(",");
    }
    $("#" + selector).val(value);
    if ($("#" + selector).prop('multiple')) {
      if(selector == "clusters-filter"){
        $('#clusters-filter').select2({
          maximumSelectionLength: 2
        });
      }else if(selector == "countries-filter"){
        $('#countries-filter').select2({
          maximumSelectionLength: 2
        });
      }else if(selector == "accounts-filter"){
        $('#accounts-filter').select2({
          maximumSelectionLength: 4
        });
      }else if(selector == "products-filter"){
        $('#products-filter').select2({
          maximumSelectionLength: 6
        });
      }else {
        $("#" + selector).select2();
      }
    }
    var nextResource = $("#" + selector).attr("data-resource");
    var nextTarget = $("#" + selector).attr("data-target");
    if (!nextResource || !nextTarget) {
      clickSubmit();
      return;
    }
    var resources = nextResource.split(",");
    var targets = nextTarget.split(",");
    for (let index = 0; index < targets.length; index++) {
      let target = targets[index];
      var resource = resources[index];
      var data = {};
      data[filter] = value;
      requestService(resource, target, data, true, true);
    }
  }

  function handleExportDataAsFile() {
    $(document).on('click', ".buttons button", function () {
      var type = $(this).attr("data-type");
      var selector = $(this).attr("data-selector");
      console.log(selector);
      var now = new Date();
      var fileName = 'report-' + now.getDay() + (now.getMonth() + 1) + now.getFullYear() + '.' + type;
      var element = document.getElementById(selector);
      hideContent(selector);

      var svg = new XMLSerializer().serializeToString($("#" + selector + " svg")[0]);
      var canvasElement = document.getElementById('canvas');
      canvg(canvasElement, svg);
      const table = $("#" + selector + " .hidden-table");
      $("#report-wrapper #table").replaceWith(table);
      var elementExport = document.getElementById("report-wrapper");

      if (type == "png") {
        html2canvas(elementExport, {
          onrendered: function (canvas) {
            var data = canvas.toDataURL("image/png");

            if (window.navigator.msSaveOrOpenBlob) {

              var byteString = atob(data.split(',')[1]);

              // write the bytes of the string to an ArrayBuffer
              var ab = new ArrayBuffer(byteString.length);

              // create a view into the buffer
              var ia = new Uint8Array(ab);

              // set the bytes of the buffer to the correct values
              for (var i = 0; i < byteString.length; i++) {
                ia[i] = byteString.charCodeAt(i);
              }

              // write the ArrayBuffer to a blob, and you're done
              const blob = new Blob([ab], {
                type: "image/png"
              });
              window.navigator.msSaveOrOpenBlob(blob, fileName);
            } else {
              var a = document.createElement('a');
              // toDataURL defaults to png, so we need to request a png, then convert for file download.
              a.href = data;
              a.download = fileName;
              a.click();
            }
            restoreContent(selector);
          }
        });


        // html2canvas(element, {
        //     onrendered: function (canvas) {
        //         var a = document.createElement('a');
        //         // toDataURL defaults to png, so we need to request a png, then convert for file download.
        //         a.href = canvas.toDataURL("image/png");
        //         a.download = fileName;
        //         canvas.width += 20;
        //         if (window.navigator.msSaveOrOpenBlob) {

        //             var byteString = atob(a.href.split(',')[1]);

        //             // write the bytes of the string to an ArrayBuffer
        //             var ab = new ArrayBuffer(byteString.length);

        //             // create a view into the buffer
        //             var ia = new Uint8Array(ab);

        //             // set the bytes of the buffer to the correct values
        //             for (var i = 0; i < byteString.length; i++) {
        //                 ia[i] = byteString.charCodeAt(i);
        //             }

        //             // write the ArrayBuffer to a blob, and you're done
        //             const blob = new Blob([ab], { type: "image/png" });
        //             window.navigator.msSaveOrOpenBlob(blob, fileName);
        //         } else {
        //             a.click();
        //         }
        //         restoreContent(selector);
        //     }
        // });

      } else if (type == "pdf") {
        var doc = new jsPDF('l', 'mm', 'a4');
        doc.addHTML(elementExport, 0, 20, function () {
          doc.save(fileName);
          restoreContent(selector);
        });
      } else {
        const contailer = document.getElementById('report-wrapper');
        const csv = [];
        const rows = contailer.querySelectorAll("table tr");
        for (let index = 0; index < rows.length; index++) {
          let rowElement = rows[index];
          const row = [];
          const cols = rowElement.querySelectorAll("td, th");
          for (let colIndex = 0; colIndex < cols.length; colIndex++) {
            let col = cols[colIndex];
            row.push(col.innerText);
          }
          csv.push(row.join(","));
        }
        const base64Content = btoa(csv.join("\n"));
        const csvContent = 'data:text/csv;base64,' + base64Content;
        if (window.navigator.msSaveOrOpenBlob) {
          const blob = new Blob([csv.join("\n")], {
            type: "text/csv"
          });
          window.navigator.msSaveOrOpenBlob(blob, fileName);
        } else {
          var link = document.createElement('a');
          link.setAttribute('href', csvContent);
          link.setAttribute('download', fileName);
          link.click();
        }
        restoreContent(selector);
      }
    });
  }

  function hideContent(selector) {
    $('#' + selector).parent().css("opacity", "0");
    $('#' + selector + ' .hidden-table').css("position", "relative");
    $('#' + selector + ' .hidden-table').css("opacity", "1");
    $('#' + selector + ' .hidden-table').css("z-index", "99999");
  }

  function restoreContent(selector) {
    $('#' + selector).parent().css("opacity", "1");
    $('#' + selector + ' .hidden-table').css("position", "fixed");
    $('#' + selector + ' .hidden-table').css("opacity", "0");
    $('#' + selector + ' .hidden-table').css("z-index", "-9999");
  }

  function clickSubmit() {
    for (let i = 0; i < Object.keys(settings.ppt_dashboard.resources).length; i++) {
      let resourceURL = Object.keys(settings.ppt_dashboard.resources)[i];
      resource = settings.ppt_dashboard.resources[resourceURL];
      requestService(resourceURL, resource, getFilters());
    }
  }

  function getGoogleArrayForField(data, index) {
    if (!data || data.length == 0) {
      return;
    }
    const finalArray = [];
    var secondField;
    for (let i = 0; i < Object.keys(data).length; i++) {
      let head = Object.keys(data)[i];
      if (i == 0) {
        secondField = Object.keys(data)[1];
      }
      const headMonths = data[head];
      for (let monthIndex = 0; monthIndex < Object.keys(headMonths).length; monthIndex++) {
        let monthName = Object.keys(headMonths)[monthIndex];
        if (!finalArray[monthIndex]) {
          var monthNameNumber = monthName.substring(0, 3);
          if (settings.ppt_dashboard.resource.indexOf("target") != -1) {
            var actualMinusTarget = headMonths[monthName][index] - data[secondField][monthName][index];
            monthNameNumber = monthNameNumber + ' (' + actualMinusTarget + ')';
          }
          const row = [monthNameNumber, headMonths[monthName][index]];
          finalArray.push(row);
        } else {
          finalArray[monthIndex].push(headMonths[monthName][index]);
        }
      }
    }

    let headers = ['Month'];
    headers = headers.concat(Object.keys(data));
    finalArray.unshift(headers);

    return finalArray;
  }

  /**
   * Filters
   */
  function addFiltersListener() {
    $(".dashboard-filter .form-control").on("change", function () {
      var value = $(this).val();
      var id = $(this).attr("id");
      // console.log('value', value);
      var idFrags = id.split("-");
      var paramName = idFrags[0];
      setFilter(value, $(this), paramName);
      if (id == "reps-filter" || id == "therapeutic-filter" || id == "quarter-filter" || id == "team-filter" || id == "accounts-filter") {
        if (validForm()) {
          $("#dashboard-submit").prop("disabled", false);
          $(".change-chart-type").prop("disabled", false);
        } else {
          $("#dashboard-submit").prop("disabled", true);
          $(".change-chart-type").prop("disabled", true);
        }
      }
      var resourceString = $(this).attr("data-resource");
      var targetString = $(this).attr("data-target");
      if (!resourceString || !targetString) {
        return;
      }
      var resources = resourceString.split(",");
      var targets = targetString.split(",");
      for (let index = 0; index < targets.length; index++) {
        let target = targets[index];
        resource = resources[index];
        if (value && resource && target) {
          data = {};
          data[paramName] = value;
          if (Array.isArray(value)) {
            if (value.length == 1 && !value[0]) {
              delete data[paramName];
            } else if (value.length > 1 && !value[0]) {
              value.splice(0, 1);
              data[paramName] = value;
            }
          }
          requestService(resource, target, data, true);
        }
        if (validForm()) {
          $("#dashboard-submit").prop("disabled", false);
          $(".change-chart-type").prop("disabled", false);
        } else {
          $("#dashboard-submit").prop("disabled", true);
          $(".change-chart-type").prop("disabled", true);
        }
      }
    });
  }
  function validForm() {
    var href = window.location.href;
    var requiredFields = ["year", "region", "clusters", "countries"];
    if (href.indexOf("target-country") == -1) {
      requiredFields.push("accounts");
    }
    if (href.indexOf("target-delivered-report") !== -1) {
      if(Drupal.settings.ppt_dashboard.roles[12]=="Comm Lead"){
        requiredFields.push("team", "therapeutic");
      }else{
        requiredFields.push("reps", "therapeutic");
      }
    }
    if (href.indexOf("expected-orders-report") !== -1) {
      if(Drupal.settings.ppt_dashboard.roles[12]=="Comm Lead"){
        requiredFields.push("team","quarter", "therapeutic","accounts");
      }else{
        requiredFields.push("quarter", "therapeutic","accounts");
      }
    }
    var formValid = true;
    for (let index = 0; index < requiredFields.length; index++) {
      let element = requiredFields[index];
      if (!searchParams_get(element)) {
        formValid = false;
      }
    }
    return formValid;
  }

  function handleUrlFilters() {
    var href = window.location.href;
    var hrefFrags = href.split("?");
    if (!hrefFrags[1]) {
      var now = new Date();
      setFilter(now.getFullYear(), $("year-filter"), "year");
      return;
    }
    var params = hrefFrags[1].split("&");
    for (let i = 0; i < params.length; i++) {
      let param = params[i];
      var paramFrags = param.split("=");
      var paramValues = paramFrags[1];
      paramValues = paramValues.split(",");
      var paramName = paramFrags[0];
      var filterId = "#" + paramName + '-filter';
      setFilter(paramValues, $(filterId), paramName, false);
    }
  }

  function setFilter(value, filterElement, paramName, pushState) {
    if (pushState == undefined) {
      pushState = true;
    }
    filterElement.val(value);
    if (pushState) {
      if (!value || (Array.isArray(value) && (value.length == 0 || (value.length == 1 && !value[0])))) {
        // searchParams_delete(paramName);
      } else {
        searchParams_set(paramName, value);
      }
      var href = window.location.href;
      window.history.pushState(href, "Dashboard", decodeURIComponent(href));
    }
  }

  function getFilters() {
    var href = window.location.href;
    var hrefFrags = href.split("?");
    if (!hrefFrags[1]) {
      return [];
    }
    var params = hrefFrags[1].split("&");
    data = {};
    for (let i = 0; i < params.length; i++) {
      let param = params[i];
      var paramFrags = param.split("=");
      var paramValues = paramFrags[1];
      paramValues = paramValues.split(",");
      if (!paramValues[0]) {
        paramValues.splice(0, 1);
      }
      var singleFilters = ["year", "region"];
      if (singleFilters.indexOf(paramFrags[0]) != -1) {
        paramValues = paramValues[0];
      }
      var paramName = paramFrags[0];
      data[paramName] = paramValues;
    }
    return data;
  }

  function setFilterOptions(result, selector, firstInit) {
    var firstOption = true;
    if (!firstInit) {
      firstInit = false;
    }

    $("#" + selector).find('option').remove();
    if (selector == 'products-filter') {
      $("#" + selector).find('optgroup').remove();
    }
    $("#" + selector).prop("disabled", false);
    var customSelect = $("#" + selector).parent().find(".ms-parent button");
    if (customSelect.length > 0) {
      customSelect.removeClass("disabled");
    }
    var selected = false;
    if (Object.keys(result).length == 1) {
      selected = true;
    }
    for (let index = 0; index < Object.keys(result).length; index++) {
      // there is special case for products filter, group options
      if (selector == 'products-filter') {
        let key = Object.keys(result)[index];
        let option = result[key];
        let html = '<optgroup label="' + option['name'] + '">';
        for (let index = 0; index < Object.keys(option.terms).length; index++) {
          let childKey = Object.keys(option.terms)[index];

          let childOption = option.terms[childKey];
          html += '<option value="' + childOption["id"] + '">' + childOption["name"] + '</option>';
        }
        html += '</optgroup>';
        $("#" + selector).append(html);

      } else if (selector == 'countries-filter') {
        let cluster = Object.keys(result)[index];
        let countries = result[cluster];
        let html = "";
        for (let i = 0; i < countries.length; i++) {
          const country = countries[i];
          html += `<option value="${country['id']}">${country['name']}</option>`;
        }
        // html += '</optgroup>';
        $("#" + selector).append(html);
      } else {
        let key = Object.keys(result)[index];
        var option = result[key];
        if (firstOption) {
          if (window.location.href.indexOf("target-delivered-report") !== -1 || window.location.href.indexOf("expected-orders-report") !== -1) {
            if (selector == "accounts-filter") {
              $("#accounts-filter").append(new Option("select an account*", "", ""));
              firstOption = false;
            }
          }
        }
        $("#" + selector).append(new Option(option["name"], option["id"], selected));
      }

    }
    if (selected) {
      $("#" + selector).trigger("change");
    }
    if ($("#" + selector).prop('multiple')) {
      if(selector == "clusters-filter"){
        $('#clusters-filter').select2({
          maximumSelectionLength: 2
        });
      }else if(selector == "countries-filter"){
        $('#countries-filter').select2({
          maximumSelectionLength: 2
        });
      }else if(selector == "accounts-filter"){
        $('#accounts-filter').select2({
          maximumSelectionLength: 4
        });
      }else if(selector == "products-filter"){
        $('#products-filter').select2({
          maximumSelectionLength: 6
        });
      }else {
        $("#" + selector).select2();
      }

    }

    if (firstInit) {
      initUrlFilters(selector);
    }
  }

  function requestService(resource, selector, data, isFilter, firstInit) {
    if (!isFilter) {
      isFilter = false;
    }
    if (!firstInit) {
      firstInit = false;
    }
    var href = window.location.href;
    if (href.indexOf("/all")) {
      data['general'] = true;
    }
    requestsNumber++;
    $("#loader-container").removeClass("hidden");
    $.ajax({
      type: "POST",
      url: "/api/ppt_resources/" + resource,
      headers: {
        "Accept": "application/json",
        'X-CSRF-Token': settings.ppt_dashboard.token
      },
      data: JSON.stringify(data),
      contentType: "application/json; charset=utf-8",
      xhrFields: {
        withCredentials: true
      },
      dataType: "json",
      success: function (result) {
        if (isFilter) {
          if (firstInit) {
            setFilterOptions(result, selector, true);
          } else {
            setFilterOptions(result, selector);
          }
        } else {
          if (selector.name == "target") {
            jQuery('#report-charts').html('');
            for (let i = 0; i < Object.keys(result).length; i++) {
              let key = Object.keys(result)[i];
              let items = result[key];
              let product = normalizeStr(key);
              product = key.replace(/\//g, '_');
              for (let i = 0; i < Object.keys(items).length; i++) {
                let key = Object.keys(items)[i];
                let item = items[key];
                let label = product.replace(/-/g, ' ') + " " + key.toUpperCase();
                label = label.replace(/_/g, '/');
                let elementId = product + "-" + key + "-" + selector.name + "-report";
                let containerId = product + "-" + key + "-" + selector.name + "-container";
                generateChartHtml(selector, elementId, containerId);
                let dataArray = getGoogleArrayForField(item, 0);
                drawChart(dataArray, elementId, label);
              }
            }
          } else if (selector.name == 'expected-orders-report') {
            if(result.length ==0){
              $("#expected-orders-error-msg").html("");
              $("#expected-orders-error-msg").css("display", "block");
              $("#expected-orders-error-msg").append('<div class="alert alert-danger" > no product found</div>');
            }else{
              $("#expected-orders-error-msg").html("");
              drawExpectedTable(result);
                $(".buttons-table").css("display", "inline-block");
            }
          }else if (selector.name == "consumptions_stocks") {
            jQuery('#report-charts').html('');
            for (let i = 0; i < Object.keys(result).length; i++) {
              let key = Object.keys(result)[i];
              let items = result[key];
              let account = key;
              let account_sanitized = normalizeStr(account);
              let Header = "<h4 class='consumptions-report-header'>Account: " + account.toUpperCase() + "</h4>";
              $('#report-charts').append(Header);
              for (let i = 0; i < Object.keys(items).length; i++) {
                let consumption_stocks = Object.keys(items)[i];
                let products = items[consumption_stocks];
                let label = (consumption_stocks + " Per Product").toUpperCase();
                let elementId = account_sanitized + "-" + consumption_stocks + "-" + selector.name + "-report";

                let containerId = account_sanitized + "-" + consumption_stocks + "-" + selector.name + "-container";
                //speical case for PieChart to sum all values of months per product
                generateChartHtml(selector, elementId, containerId);
                let dataArray = [];
                if (chartType === "PieChart") {
                  let products_new = [];
                  for (const product in products) {
                    if (products.hasOwnProperty(product)) {
                      let product_total = 0;
                      let product_data = products[product];
                      for (const month in product_data) {
                        if (product_data.hasOwnProperty(month)) {
                          product_total += parseInt(product_data[month][0]);
                        }
                      }
                      products_new.push([product, product_total]);
                    }
                  }
                  dataArray = products_new;
                  dataArray.unshift(['product', 'value']);
                } else {
                  dataArray = getGoogleArrayForField(products, 0);
                }
                drawChart(dataArray, elementId, label);
              }
            }
          } else if (selector.name == "planned orders") {
            jQuery('#report-charts').html('');
            for (let i = 0; i < Object.keys(result).length; i++) {
              let key = Object.keys(result)[i];
              var items = result[key];
              //used regex for replacement as the string method replaces for only first occurence.
              var product = normalizeStr(key);
              var label = product.replace(/-/g, ' ', true);
              var elementId = product + "-" + "-report";
              var containerId = product + "-" + "-container";
              generateChartHtml(selector, elementId, containerId);
              var dataArray = getGoogleArrayForField(items, 0);
              drawChart(dataArray, elementId, label);
            }
          } else if (selector.name == "orders-report") {
            $("#table_div").html("");
            $.each(result, function (index, value) {
              var account_Id = "account_" + value["account_id"];
              $("#table_div").append("<div id='" + account_Id + "-container'></div>");
              $("#" + account_Id + "-container").append("<div class='row'>" +
                '<div class="buttons-table col-md-1" data-html2canvas-ignore="true">\n' +
                '<button class="btn btn-primary btn-img" data-selector="' + account_Id + '-report" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>\n' +
                '<button class="btn btn-primary btn-csv" data-selector="' + account_Id + '-report" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>\n' +
                '</div>' +
                "<div class='col-md-11' id='" + account_Id + "-report'>" + "</div>" +
                "</div>");
              $("#" + account_Id + "-report").append("<h3>Account: " + value["account_name"] + "</h3>");
              $("#" + account_Id + "-report").append("<div id='" + account_Id + "-table'></div>");
              google.charts.load('current', {
                'packages': ['table']
              });
              google.charts.setOnLoadCallback(function () {
                drawTable(value['products'], account_Id + "-table");
              });
            });
          } else if (selector.name.indexOf('delivered-report') !== -1) {
            google.charts.load('current', { 'packages': ['table'] });
            google.charts.setOnLoadCallback(function () {
              drawTargetTable(result);
              $(".buttons-table").css("display", "inline-block");
            });
          } else if (selector.name == "next_planned") {
            jQuery('#report-charts').html('');
            // $('#planned-products-report').html('');
            // if(result.length == 0){
            //   $('#planned-products-report').append('<h3 class="text-center">No data found</h3>');
            // }
            for (let i = 0; i < Object.keys(result).length; i++) {
              let key = Object.keys(result)[i];
              var products = result[key];
              var label = "Next Planned Orders"
              var elementId = key + "-products" + "-report";
              var containerId = key + "-products" + "-container";
              generateChartHtml(selector, elementId, containerId);
              let dataArray = [];
              if (chartType === "PieChart") {
                let products_new = [];
                for (const product in products) {
                  if (products.hasOwnProperty(product)) {
                    let product_total = 0;
                    let product_data = products[product];
                    for (const month in product_data) {
                      if (product_data.hasOwnProperty(month)) {
                        product_total += parseInt(product_data[month][0]);
                      }
                    }
                    products_new.push([product, product_total]);
                  }
                }
                dataArray = products_new;
                dataArray.unshift(['product', 'value']);
              } else {
                dataArray = getGoogleArrayForField(products, 0);
              }
              drawChart(dataArray, elementId, label);
            }
          }  else if (selector.name == "delivered_planned") {
            jQuery('#report-charts').html('');
            // $('#delivered-products-report').html('');
            // if(result.length == 0){
            //   $('#delivered-products-report').append('<h3 class="text-center">No data found</h3>');
            // }

            for (let i = 0; i < Object.keys(result).length; i++) {
              let key = Object.keys(result)[i];
              var products = result[key];
              var label = "Delivered Planned Orders"
              var elementId = key + "-products" + "-report";
              var containerId = key + "-products" + "-container";
              generateChartHtml(selector, elementId, containerId);
              let dataArray = [];
              if (chartType === "PieChart") {
                let products_new = [];
                for (const product in products) {
                  if (products.hasOwnProperty(product)) {
                    let product_total = 0;
                    let product_data = products[product];
                    for (const month in product_data) {
                      if (product_data.hasOwnProperty(month)) {
                        product_total += parseInt(product_data[month][0]);
                      }
                    }
                    products_new.push([product, product_total]);
                  }
                }
                dataArray = products_new;
                dataArray.unshift(['product', 'value']);
              } else {
                dataArray = getGoogleArrayForField(products, 0);
              }
              drawChart(dataArray, elementId, label);
            }
          } else {
            //all product dosages are on same chart
            // console.log("here!");
            getFilters();
            for (let index = 0; index < selector.selectors.length; index++) {
              let sele = selector.selectors[index];
              var label = sele.toUpperCase() + " " + selector.label;
              var elementId = sele + "-" + selector.name + "-report";
              if (selector.name.indexOf('target') !== -1) {
                for (let i = 0; i < Object.keys(result).length; i++) {
                  let key = Object.keys(result)[i];
                  item = result[key];
                  generateChartHtml(selector, elementId, containerId);
                  var dataArray = getGoogleArrayForField(item, 0);
                  drawChart(dataArray, elementId, label);
                }
              } else if (selector.name.indexOf('pie-indications') !== -1) {
                var dataArray = Object.keys(result[sele]).map(function (key) {
                  return [key, result[sele][key]];
                });
                drawChart(dataArray, elementId, label);
              } else if (chartType === "PieChart") {
                // sele is cot, npr, drop fo per product or indications
                let products_new = [];
                for (const product in result) {
                  if (result.hasOwnProperty(product)) {
                    let product_total = 0;
                    let product_data = result[product];
                    for (const month in product_data) {
                      if (product_data.hasOwnProperty(month)) {
                        product_total += parseInt(product_data[month][index]);
                      }
                    }
                    products_new.push([product, product_total]);
                  }
                }
                dataArray = products_new;
                dataArray.unshift(['product', 'value']);
                // console.log(dataArray);
                drawChart(dataArray, elementId, label);
              } else {
                var dataArray = getGoogleArrayForField(result, index);
                // console.log(dataArray);
                drawChart(dataArray, elementId, label);
              }
            }
          }
        }
        requestsNumber--;
        if (requestsNumber == 0) {
          $("#loader-container").addClass("hidden");
        }
      },
      failure: function (errMsg) {
        console.log(errMsg);
      }
    });
  }

  function normalizeStr(str) {
    if (str)
      return str.replace(/([ #;?%&,.+*~\':"!^$[\]()=>|\/@])/g, '-');

    return str;
  }

  function drawChart(dataArray, selector, label) {
    //escaping ' in product name
    selector = normalizeStr(selector);
    // console.log(selector);
    $("#" + selector).parent().find(".buttons").addClass("hidden");
    var element = document.getElementById(selector);
    if (!element) {
      return;
    }
    $(element).html("");
    if (!dataArray || dataArray.length == 0 || (chartType === "PieChart" && dataArray.length <= 1)) {
      // $(element).html("<h3 class='text-center'>No data found</h3>");
      return;
    }
    if (chartType == "ComboChart") {
      chartOptions.seriesType = 'bars';
    } else {
      delete chartOptions.seriesType;
    }
    chartOptions.title = label;
    if (!google.visualization || !google.visualization.ChartWrapper) {
      return;
    }

    var chartData = {
      chartType: chartType,
      dataTable: dataArray,
      containerId: selector,
      options: chartOptions
    };
    // console.log(selector);

    if (selector.indexOf('pie-indications') !== -1) {
      chartData.chartType = 'PieChart';
      chartData.options.pieHole = 0.6;
    } else if (selector.indexOf('target-cot-target') !== -1 || selector.indexOf('target-npr-target') !== -1) {
      chartData.chartType = 'ComboChart';
      chartData.options.series = {
        1: {
          type: 'line'
        }
      };
      chartData.options.seriesType = 'bars';
    }

    var wrapper = new google.visualization.ChartWrapper(chartData);
    wrapper.draw();

    if (selector.indexOf('pie-indications') !== -1) {
      return;
    }

    $("#" + selector).parent().find(".buttons").removeClass("hidden");
    var headers_string = '<thead><tr>';
    for (let i = 0; i < dataArray[0].length; i++) {
      let th = dataArray[0][i];
      headers_string += '<th>' + th + '</th>';
    }
    headers_string += '</tr></thead>';

    var content_string = '<tbody>';
    for (var index = 0; index < dataArray.length; index++) {
      if (index != 0) {
        let row = dataArray[index];

        content_string += '<tr>';
        for (let i = 0; i < row.length; i++) {
          let td = row[i];
          content_string += '<td>' + td + '</td>';
        }
        content_string += '</tr>';
      }

    }
    content_string += '</tbody>';
    $('#' + selector).parent().find(".hidden-table").remove();
    $('#' + selector).parent().append("<div class='table-responsive hidden-table'><table class='table'>" + headers_string + content_string + "</table></div>");
  }

  function generateChartHtml(selector, elementId, containerId) {
    //escaping ' in product name
    containerId = normalizeStr(containerId);
    elementId = normalizeStr(elementId);
    var html = '<div class="row reports-container-row">' +
      '<div class="reports-container" id="' + containerId + '" class="col-xs-12">' +
      '<div id="' + elementId + '"></div>' +
      '<div class="buttons" data-html2canvas-ignore="true">' +
      '<button class="btn btn-primary btn-pdf" data-selector="' + containerId + '" data-type="pdf"><i class="fa fa-file-pdf-o" aria-hidden="true"></i></button>' +
      '<button class="btn btn-primary btn-img" data-selector="' + containerId + '" data-type="png"><i class="fa fa-picture-o" aria-hidden="true"></i></button>' +
      '<button class="btn btn-primary btn-csv" data-selector="' + containerId + '" data-type="csv"><i class="fa fa-table" aria-hidden="true"></i></button>' +
      '</div></div></div>';

    $('#report-charts').append(html);
  }


  function searchParams_get(key) {
    var href = window.location.href;
    var hrefFrags = href.split('?');
    var searchParams = hrefFrags[1];
    if (!searchParams) {
      return null;
    }
    var params = searchParams.split("&");
    for (let index = 0; index < params.length; index++) {
      let param = params[index];
      let paramFrams = param.split("=");
      if (paramFrams[0] == key) {
        return paramFrams[1];
      }
    }
    return null;
  }

  function searchParams_set(key, value) {
    var href = window.location.href;
    var hrefFrags = href.split("?");
    var searchParams = hrefFrags[1];
    if (searchParams) {
      var params = searchParams.split("&");
      var found = false;
      for (let index = 0; index < params.length; index++) {
        let param = params[index];
        let paramFrams = param.split("=");
        if (paramFrams[0] == key) {
          found = true;
          params[index] = key + '=' + value.toString();
        }
      }
      if (!found) {
        window.history.pushState('', '', href + '&' + key + '=' + value);
      } else {
        window.history.pushState('', '', hrefFrags[0] + '?' + params.join("&"));
      }
    } else {
      window.history.pushState('', '', href + '?' + key + '=' + value);
    }
  }

  function searchParams_delete(key) {
    var href = window.location.href;
    var hrefFrags = href.split('?');
    var searchParams = hrefFrags[1];
    if (!searchParams) {
      return;
    }
    var params = searchParams.split("&");
    for (let index = 0; index < params.length; index++) {
      let param = params[index];
      let paramFrams = param.split("=");
      if (paramFrams[0] == key) {
        params.splice(index, 1);
      }
    }
    window.history.pushState('', '', hrefFrags[0] + '?' + params.join("&"));
  }

  // drawExpectedTable
  function drawExpectedTable(result) {
    $("#expected-table-tr").html('');
    $("#expected-table-tr").append('<td></td>')
    $("#month-header").html('');
    $("#month-header").append('<td>Dosage</td>');
    for (let i = 0; i < Object.keys(result).length; i++) {
      let key = Object.keys(result)[i];
      var months = result[key];
      for (let i = 0; i < Object.keys(months).length; i++) {
        let month = Object.keys(months)[i];
        var data = months[month];
        if ($("#expected-table-tr td").length < 5) {
          $("#expected-table-tr").append('<td colspan="4" style="border-left: 2px solid #3c8dbc">' + month + '</td>');
        }
        if ($("#month-header td").length < 16) {
          if (month == "ytd") {
            $("#month-header").append('<td style="border-left: 2px solid #3c8dbc">Total delivered Order</td>');
            $("#month-header").append('<td >Consumption</td>');
            $("#month-header").append('<td >Stocks</td>');
            $("#month-header").append('<td >Month on Hand</td>');
          } else {
            $("#month-header").append('<td style="border-left: 2px solid #3c8dbc">Stocks</td>');
            $("#month-header").append('<td >Consumption</td>');
            $("#month-header").append('<td >Expected Orderes</td>');
            $("#month-header").append('<td >Actual delivered Order</td>');
          }
        }
      }
    }
    var tbody = "";
    $("#expected-table-body").html("");
    $.each(result, function (dosage, months) {
      tbody = "";
      tbody+="<tr>";
      tbody+="<td style='border-right: 2px solid #3c8dbc'>"+dosage+"</td>";
      var count=1;
      $.each(months, function (month, recodrd) {
        $.each(recodrd, function (index, value) {
          count++;
          if(count%5==0){
            tbody+="<td style='border-right: 2px solid #3c8dbc\ \ '>"+value.toLocaleString()+"</td>";
            count=1;
          }else{
            tbody+="<td>"+value.toLocaleString()+"</td>";
          }
        });
      });
      tbody+="</tr>";
      $("#expected-table-body").append(tbody);
    });
    $("#expected-orders-table").css("display","block");
  }
  // Draw target delivered table.
  function drawTargetTable(result) {
    var data = new google.visualization.DataTable();
    data.addColumn('string', 'Dosage');
    data.addColumn('number', 'Total QTY');
    data.addColumn('number', 'Delivered QTY');
    data.addColumn('number', 'NTM QTY');
    data.addColumn('number', 'Total Target $');
    data.addColumn('number', 'Delivered $');
    data.addColumn('number', 'NTM $');
    var rows = [];
    if (typeof result[0] === 'string') {
    } else {
      $.each(result, function (index, value) {
        arr = [];
        arr.push(value["product_name"]);
        arr.push(value["target_quantity"]);
        arr.push(value["delivered_quantity"]);
        arr.push(value["ntm_quantity"]);
        arr.push({ v: value["total_target_value"], f: '' + value['total_target_value'].toLocaleString() });
        arr.push({ v: value["total_delivered_value"], f: '' + value['total_delivered_value'].toLocaleString() });
        arr.push({ v: value["total_ntm_value"], f: '' + value['total_ntm_value'].toLocaleString() });
        rows.push(arr);
      });
    }
    data.addRows(rows);
    var table = new google.visualization.Table(document.getElementById('target-delivered-table'));
    table.draw(data, { showRowNumber: false, width: '100%', height: '100%' });
  }

  // Draw table for orders report.
  function drawTable(products, elementId) {
    var data = new google.visualization.DataTable();
    data.addColumn('string', 'Dosage');
    data.addColumn('string', 'Type');
    data.addColumn('number', 'December');
    data.addColumn('number', 'January');
    data.addColumn('number', 'February');
    data.addColumn('number', 'March');
    data.addColumn('number', 'April');
    data.addColumn('number', 'May');
    data.addColumn('number', 'June');
    data.addColumn('number', 'July');
    data.addColumn('number', 'August');
    data.addColumn('number', 'September');
    data.addColumn('number', 'October');
    data.addColumn('number', 'November');

    var rows = [];
    // Loop for generate dataTable array based on api response.
    $.each(products, function (i, v) {
      var dataArray = []
      if (v["stock"] != undefined) {
        dataArray = []
        dataArray.push(v["product_name"]);
        dataArray.push("Stock");
        dataArray = dataArray.concat(v["stock"]);
        rows.push(dataArray);
      } else {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Stock");
        dataArray = dataArray.concat([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
        rows.push(dataArray);
      }
      if (v["consumption"] != undefined) {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Consumption");
        dataArray = dataArray.concat(v["consumption"]);
        rows.push(dataArray);
      } else {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Consumption");
        dataArray = dataArray.concat([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
        rows.push(dataArray);
      }
      if (v["planned_quantity"] != undefined) {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Next Orders");
        dataArray = dataArray.concat(v["planned_quantity"]);
        rows.push(dataArray);
      } else {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Next Orders");
        dataArray = dataArray.concat([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
        rows.push(dataArray);
      }
      if (v["delivered_quantity"] != undefined) {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Delivered Orders");
        dataArray = dataArray.concat(v["delivered_quantity"]);
        rows.push(dataArray);
      } else {
        dataArray = []

        dataArray.push(v["product_name"]);
        dataArray.push("Delivered Orders");
        dataArray = dataArray.concat([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]);
        rows.push(dataArray);
      }
    });
    data.addRows(rows);
    var table = new google.visualization.Table(document.getElementById(elementId));
    google.visualization.events.addOneTimeListener(table, 'ready', function () {
      var rowLabel = null;
      var rowIndex;
      var rowSpan;
      var rows = document.getElementById(elementId).getElementsByTagName('tr');
      Array.prototype.forEach.call(rows, function (row, index) {
        if (rowLabel !== row.cells[0].innerHTML) {
          rowLabel = row.cells[0].innerHTML;
          rowIndex = index;
          if (rowSpan > 1) {
            rows[index - rowSpan].cells[0].rowSpan = rowSpan;
          }
          rowSpan = 1;
        } else {
          row.removeChild(row.cells[0]);
          if (index === (rows.length - 1)) {
            rows[index - rowSpan].cells[0].rowSpan = ++rowSpan;
          } else {
            rowSpan++;
          }
        }
      });

    });
    table.draw(data, {
      allowHtml: true,
      width: '100%',
      height: '100%',
    });
  }

  function handleTableDataASFile() {
    $(document).on('click', ".buttons-table .btn-img", function () {
      var type = $(this).attr("data-type");
      var selector = $(this).attr("data-selector");
      var now = new Date();
      $(".col-md-11").css("z-index", "-1");
      $(".col-md-11").css("width", "inherit");
      var fileName = 'report-' + now.getDay() + (now.getMonth() + 1) + now.getFullYear() + '.' + type;
      var elementExport = document.getElementById(selector);
      html2canvas(elementExport, {
        onrendered: function (canvas) {
          var data = canvas.toDataURL("image/png");
          if (window.navigator.msSaveOrOpenBlob) {
            var byteString = atob(data.split(',')[1]);
            // write the bytes of the string to an ArrayBuffer
            var ab = new ArrayBuffer(byteString.length);
            // create a view into the buffer
            var ia = new Uint8Array(ab);
            // set the bytes of the buffer to the correct values
            for (var i = 0; i < byteString.length; i++) {
              ia[i] = byteString.charCodeAt(i);
            }
            // write the ArrayBuffer to a blob, and you're done
            const blob = new Blob([ab], {
              type: "image/png"
            });
            window.navigator.msSaveOrOpenBlob(blob, fileName);
          } else {
            var a = document.createElement('a');
            // toDataURL defaults to png, so we need to request a png, then convert for file download.
            a.href = data;
            a.download = fileName;
            a.click();
          }
          $(".col-md-11").attr("style", "");
        }
      });
    });
    $(document).on('click', ".buttons-table .btn-csv", function () {
      var type = $(this).attr("data-type");
      var selector = $(this).attr("data-selector");
      var now = new Date();
      var fileName = 'report-' + now.getDay() + (now.getMonth() + 1) + now.getFullYear() + '.' + type;
      var csv = [];
      var rows = document.querySelectorAll("#" + selector + " table tr");
      // Loop for table rows.
      for (var i = 0; i < rows.length; i++) {
        var row = [];
        var cols = rows[i].querySelectorAll("td, th");
        // Loop for get text content of each td and th in table row.
        for (var j = 0; j < cols.length; j++) {
          row.push(cols[j].innerText.replace(',', ''));
        }
        csv.push(row.join(","));
      }
      // Download CSV file
      downloadCSV(csv.join("\n"), fileName);
    });
  }

  function downloadCSV(csv, filename) {
    var csvFile;
    var downloadLink;
    // CSV file
    csvFile = new Blob([csv], {
      type: "text/csv"
    });
    // Download link
    downloadLink = document.createElement("a");
    // File name
    downloadLink.download = filename;
    // Create a link to the file
    downloadLink.href = window.URL.createObjectURL(csvFile);
    // Hide download link
    downloadLink.style.display = "none";
    // Add the link to DOM
    document.body.appendChild(downloadLink);
    // Click download link
    downloadLink.click();
  }


})(jQuery);
