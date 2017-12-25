<?php

class FeeController extends EntityAPIController {
  public function create(array $values = array()) {
    // Add is_new property if it is not set.
    //set created
    $values['created'] = REQUEST_TIME;
    $values['Changed'] = REQUEST_TIME;
    $values += array(
      'is_new' => TRUE
    );

    // If there is a class for this entity type, instantiate it now.
    if (isset( $this->entityInfo ['entity class'] ) && $class = $this->entityInfo ['entity class']) {
      $entity = new $class( $values, $this->entityType );
    }
    else {
      $entity = ( object ) $values;
    }

    return $entity;
  }
}
