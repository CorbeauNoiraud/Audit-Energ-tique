// Create the charts when the web page loads
window.addEventListener('load', onload);

function onload(event) {
    chartT = createTemperatureChart();
    chartH = createCourant1Chart();
    chartP = createCourant2Chart();
}

// Create Temperature Chart
function createTemperatureChart() {
    var chart = new Highcharts.Chart({
        chart: {
            renderTo: 'chart-temperature',
            type: 'spline'
        },
        series: [{
            name: 'BME280'
        }],
        title: {
            text: undefined
        },
        plotOptions: {
            line: {
                animation: false,
                dataLabels: {
                    enabled: true
                }
            }
        },
        xAxis: {
            type: 'datetime',
            dateTimeLabelFormats: { second: '%H:%M:%S' }
        },
        yAxis: {
            title: {
                text: 'Temperature Celsius Degrees'
            }
        },
        credits: {
            enabled: false
        }
    });
    return chart;
}

// Create Humidity Chart
function createCourant1Chart() {
    var chart = new Highcharts.Chart({
        chart: {
            renderTo: 'chart-courant1',
            type: 'spline'
        },
        series: [{
            name: 'SCT 013 (1)'
        }],
        title: {
            text: undefined
        },
        plotOptions: {
            line: {
                animation: false,
                dataLabels: {
                    enabled: true
                }
            },
            series: {
                color: '#50b8b4'
            }
        },
        xAxis: {
            type: 'datetime',
            dateTimeLabelFormats: { second: '%H:%M:%S' }
        },
        yAxis: {
            title: {
                text: 'Courant (A)'
            }
        },
        credits: {
            enabled: false
        }
    });
    return chart;
}

// Create Pressure Chart
function createCourant2Chart() {
    var chart = new Highcharts.Chart({
        chart: {
            renderTo: 'chart-courant2',
            type: 'spline'
        },
        series: [{
            name: 'SCT 013 (2)'
        }],
        title: {
            text: undefined
        },
        plotOptions: {
            line: {
                animation: false,
                dataLabels: {
                    enabled: true
                }
            },
            series: {
                color: '#A62639'
            }
        },
        xAxis: {
            type: 'datetime',
            dateTimeLabelFormats: { second: '%H:%M:%S' }
        },
        yAxis: {
            title: {
                text: 'Courant 2 (A)'
            }
        },
        credits: {
            enabled: false
        }
    });
    return chart;
}