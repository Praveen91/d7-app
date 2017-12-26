(function ($) {
    Drupal.behaviors.AppBehavior = {
        attach: function (context, settings) {
            $(".table-list-wrapper a.action").click(function () {
                if (confirm('Would you like to open this table?')) {
                    $(".loading").show();
                    var id = $(this).attr('data');
                    $.ajax({
                        url: "/ajax/app/temp/order/" + id
                    })
                        .done(function (data) {
                            window.location.reload();
                        });
                } else {
                    //do nothing
                }

            });

            //remove item temp

            $(".table-list-wrapper a.delete-item").each(function () {
                $(this).click(function () {
                    if (confirm('Do you want to delete this menu?')) {
                        var id = $(this).attr('data');
                        $.ajax({
                            url: "/ajax/app/delete/order-item/" + id
                        })
                            .done(function (data) {
                                $("#cook-table-wrapper").replaceWith(data);
                                Drupal.attachBehaviors('#cook-table-wrapper');
                            });
                    } else {
                        //do no thing
                    }


                });
            });
            //reload when close modal
            $(".ctools-modal-content .modal-header a.close").click(function () {
                window.location.reload();
            });

            //cancel table
            $(".table-list-wrapper a.cancel-table").each(function () {
                $(this).click(function () {
                    if (confirm('Would you like to delete this table?')) {
                        $(".loading").show();
                        var id = $(this).attr('data');
                        $.ajax({
                            url: "/ajax/app/delete/order/" + id
                        })
                            .done(function (data) {
                                window.location.reload();
                            });
                    } else {
                        //do nothing
                    }

                });
            });

            //add menu mobile
            $(".menu-mobile a").click(function () {
                $("#navigation .region-menu ul.menu").toggle();
            });
            //add defualt date
            $(".form-item-from input").val($(".fromdate_value").val());
            $(".form-item-to input").val($(".todate_value").val());
            function getQueryVariable(variable) {
                var query = window.location.search.substring(1);
                var vars = query.split("&");
                for (var i=0;i<vars.length;i++) {
                    var pair = vars[i].split("=");
                    if (pair[0] == variable) {
                        return pair[1];
                    }
                }
            }


        }
    };

}(jQuery));
