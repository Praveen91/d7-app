<?php

/**
 * Implement OrderViewsController
 */
class OrderViewsController extends EntityDefaultViewsController
{
  function views_data() {
    $data = parent::views_data();
    $data['orders']['created']['field']['handler'] = 'views_handler_field_date';
    $data['orders']['changed']['field']['handler'] = 'views_handler_field_date';
    $data['orders']['created']['filter']['handler'] = 'views_handler_filter_date';
    $data['orders']['changed']['filter']['handler'] = 'views_handler_filter_date';
    return $data;
  }
}
