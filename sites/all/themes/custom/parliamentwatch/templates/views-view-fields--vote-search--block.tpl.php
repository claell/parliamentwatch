<?php
$image = theme('image_style', array(
  'style_name' => 'pw_portrait_xs', //Configure style here!
  'path' => $row->_entity_properties['field_vote_user:entity object']->field_user_picture['und'][0]['uri'],
));
$user_title = $row->_field_data['field_vote_user:field_user_title']['entity']->field_user_title['und'][0]['value'];
$user_fname = $row->_field_data['field_vote_user:field_user_title']['entity']->field_user_fname['und'][0]['value'];
$user_lname = $row->_field_data['field_vote_user:field_user_title']['entity']->field_user_lname['und'][0]['value'];
$user_full_name  = ($user_title)?$user_title." ":"";
$user_full_name .= $user_fname." ".$user_lname;
?>
<h4 class="push-bottom-xs">
  <a href="/profile/<?php echo $row->_entity_properties['field_vote_user:name'][0];?>"><?php echo $user_full_name; ?> (<?php echo $row->_entity_properties['field_vote_user:field_user_party:name'][0]?>)</a> zu &bdquo;<?php echo $row->_entity_properties['field_vote_node:title'][0]; ?>&ldquo;
</h4>
<div class="push-bottom-s">
    <span class="pw-voting">
      Position von <?php echo $user_full_name; ?>:
      <?php if ($row->_entity_properties['field_vote:name'][0] == "yes"): ?>
        <span class="yes block vote">dafür gestimmt</span>
      <?php endif; ?>
      <?php if ($row->_entity_properties['field_vote:name'][0] == "no"): ?>
        <span class="no block vote">dagegen gestimmt</span>
      <?php endif; ?>
      <?php if ($row->_entity_properties['field_vote:name'][0] == "abstain"): ?>
        <span class="abstain block vote">enthalten</span>
      <?php endif; ?>
      <?php if ($row->_entity_properties['field_vote:name'][0] == "no-show"): ?>
        <span class="no-show block vote">nicht beteiligt</span>
      <?php endif; ?>
    </span>
</div>
<div class="float-left pw-kc-profile-picture push-bottom-s">
  <div class="file-image">
    <a href="/profile/<?php echo $row->_entity_properties['field_vote_user:name'][0];?>" title="Profil öffnen"><?php echo $image ?></a>
  </div>
</div>
<div class="statement">
  <?php if (strlen($row->_entity_properties['body:value']) > 0): ?>
    <blockquote>
      <div class="pw-expander"><div><?php echo check_markup($row->_entity_properties['body:value']); ?></div></div>
    </blockquote>
  <?php endif ?>
</div>
<div class="text-right">
  <a href="/profile/<?php echo $row->_entity_properties['field_vote_user:name'][0];?>?question_form" class="icon-politician">jetzt zur Position befragen</a>
</div>