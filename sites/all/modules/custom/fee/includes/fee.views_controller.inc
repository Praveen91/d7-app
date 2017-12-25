<?php
class FeeViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    $data['fee']['created']['field']['handler'] = 'views_handler_field_date';
    $data['fee']['created']['filter']['handler'] = 'views_handler_filter_date';
    $data['fee']['changed']['field']['handler'] = 'views_handler_field_date';
    $data['fee']['changed']['filter']['handler'] = 'views_handler_filter_date';
    $data['fee']['fee_date']['field']['handler'] = 'views_handler_field_date';
    $data['fee']['fee_date']['filter']['handler'] = 'views_handler_filter_date';
    return $data;
  }
}
