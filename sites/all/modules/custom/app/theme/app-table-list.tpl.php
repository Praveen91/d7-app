<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/10/16
 * Time: 5:57 PM
 * To change this template use File | Settings | File Templates.
 */
global $user;
?>
<script type="text/javascript">
  setInterval(function () {
    jQuery(".loading").show();
    window.location.reload();
  }, 120000);
</script>
<div class="large-12 list-table columns">
  <table class="table-list-wrapper">
    <tr>
      <th> Code </th>
      <th> table name </th>
      <th> Status </th>
      <th> Start time </th>
      <th> time of use </th>
      <th> Money / h </th>
      <th> Sum up </th>
      <th> Activities </th>
      <th> Transfer table </th>
      <th> Menu </th>
      <th> Re-enter the time </th>
      <th> Cancel </th>
    </tr>
    <tbody>
    <?php if ($tables): ?>
      <?php foreach ($tables as $key => $table): ?>
        <tr class="table-<?php print $table->id; ?> <?php if ($table->order): ?> active <?php endif; ?>"
            data="<?php print $table->id; ?>">
          <td><span class="mobile-app">Number of tables: </span><?php print $table->id; ?></td>
          <td><span class="mobile-app">Table name: </span><?php print $table->name; ?></td>
          <td>
            <span class="mobile-app">Status: </span>
            <?php if ($table->order): ?>
              <?php print t('Active'); ?>
            <?php else: ?>
              <?php print t('Inactive'); ?>
            <?php endif; ?>
          </td>
          <td>
            <span class="mobile-app">The start time: </span>
            <?php if ($table->order): ?>
              <?php print date('H:i', $table->order->start); ?>
            <?php else: ?>
              <?php print t('00:00'); ?>
            <?php endif; ?>
          </td>
          <td>
            <span class="mobile-app">Used Time: </span>
            <?php if ($table->order): ?>
              <?php print $table->time_use; ?>
            <?php else: ?>
              <?php print t('00:00'); ?>
            <?php endif; ?>
          </td>
          <td><span class="mobile-app">Price: </span><?php print number_format($table->price); ?> đ</td>
          <td><span class="mobile-app">Price for use: </span><?php print $table->current_amount; ?> đ</td>
          <td>
            <span class="mobile-app">Action: </span>
            <?php if ($table->order): ?>
              <a id="edit-cancel" data="<?php print $table->id ?>" class="ctools-use-modal"
                 href="/app/order/bill/<?php print $table->id ?>/nojs"><?php print t('Thanh toán') ?></a>
            <?php else: ?>
              <a class="action" data="<?php print $table->id ?>" href="#"><?php print t('Begin') ?></a>
            <?php endif; ?>
          </td>
          <td>
            <span class="mobile-app">Change table: </span>
            <?php if ($table->order): ?>
              <a class="ctools-use-modal" href="/app/table/change/<?php print $table->id ?>/nojs"><img width="30" height="auto" src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/forward.gif"/></a>
            <?php else: ?>
              <img width="30" height="auto"
                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/forward.gif"/>
            <?php endif; ?>
          </td>
          <td>
            <span class="mobile-app">Add menu: </span>
            <?php if ($table->order): ?>
              <a class="ctools-use-modal" href="/app/food/add/<?php print $table->id ?>/nojs"><img width="30" height="auto" src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/list-add.gif"/></a>
            <?php else: ?>
              <img width="30" height="auto"
                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/list-add.gif"/>
            <?php endif; ?>
          </td>
          <td>
            <?php if (!in_array('seller', $user->roles)): ?>
              <span class="mobile-app">Reset time: </span>
              <?php if ($table->order): ?>
                <a id="edit-cancel" class="ctools-use-modal"
                   href="/app/hour/change/<?php print $table->id ?>/nojs"><?php print t('Re-enter the hours') ?></a>
              <?php else: ?>
                <?php print t('Re-enter the hours') ?>
              <?php endif; ?>
            <?php endif; ?>
          </td>
          <td>
            <?php if (!in_array('seller', $user->roles)): ?>
              <span class="mobile-app">Delete the table: </span>
              <?php if ($table->order): ?>
                <a data="<?php print $table->order->id ?>" class="cancel-table">
                  <img width="20"
                       height="auto"
                       src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/delete-icon.gif"/>
                </a>
              <?php else: ?>
                <img width="20"
                     height="auto"
                     src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/delete-icon.gif"/>
              <?php endif; ?>
            <?php endif; ?>
          </td>
        </tr>
      <?php endforeach; ?>
    <?php endif; ?>
    </tbody>
  </table>
</div>

<div style="display: none;" class="loading"><img
      src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/loading7_orange.gif" width="100"
      height="auto"/></div>
