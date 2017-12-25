<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 7/6/16
 * Time: 12:14 AM
 * To change this template use File | Settings | File Templates.
 */
?>
<div class="header-total-fun">
  <h3>Tổng chi phí: <?php print number_format($fee['total']); ?> đ</h3>
</div>
<table>
  <tr><th>ID</th><th>Ngày</th><th>Lý do</th><th>Tổng cộng</th></tr>
  <tbody>
  <?php if($fee['fees']): ?>
    <?php foreach($fee['fees'] as $fe): ?>
      <tr>
        <td><?php print $fe->id; ?></td>
        <td><?php print format_date($fe->fee_date,'custom','d/m/Y'); ?></td>
        <td><?php print $fe->reason; ?></td>
        <td><?php print number_format($fe->fee_total); ?> đ</td>
      </tr>
    <?php endforeach;?>
  <?php endif; ?>
  </tbody>
</table>