<?php
/**
 * @file
 * Page callbacks for the High Country Brewer's Alliance website.
 */

/**
 * Page callback for the /home page.
 */
function hcba_home() {

  // Don't display the page title
  drupal_set_title('');

  drupal_add_css(drupal_get_path('module', 'hcba_core') . '/css/hcba_home.css');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcba_member')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('title', 'ASC');

  $result = $query->execute();
  $members_nids = array_keys($result['node']);

  $members = array();
  foreach ($members_nids as $member) {
    $member_entity = entity_metadata_wrapper('node', $member);

    $members[] = array(
      'name' => $member_entity->label(),
      'latitude' => $member_entity->field_hcba_member_address->latitude->value(),
      'longitude' => $member_entity->field_hcba_member_address->longitude->value(),
      'link' => $member_entity->field_hcba_member_website->url->value(),
      'logo' => '<img src="' . image_style_url('medium', $member_entity->field_hcba_member_logo->value()['uri']) . '" class="img-responsive center-block" />',
    );
  }

  $members = array_chunk($members, 3);

  return theme('hcba_home', array('members' => $members));
}
