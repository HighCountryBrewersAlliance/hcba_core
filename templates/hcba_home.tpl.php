<div class="container">
  <div class="row">
    <div class="col-xs-12">
      <div class="page-header">
        <h1>Members</h1>
      </div>
    </div>
  </div>

  <?php foreach ($members as $member_row): ?>
  <div class="row">
    <?php foreach ($member_row as $member): ?>
    <div class="col-xs-12 col-sm-4">
      <div class="text-center">
        <a href="<?php print $member['link']; ?>">
          <?php print $member['logo']; ?>
        </a>
      </div>
      <h3 class="text-center">
        <?php print $member['name']; ?>
      </h3>
    </div>
    <?php endforeach; ?>
  </div>
  <?php endforeach; ?>
</div>
