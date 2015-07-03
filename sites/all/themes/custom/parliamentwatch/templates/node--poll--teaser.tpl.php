<div class="pw-list-item">
  <h3><?php print $title; ?></h3>
  <div class="sharethis-wrapper">
    <span class="st_sharethis_hcount" st_url="https://www.abgeordnetenwatch.de<?php print $node_url; ?>" st_title="<?php print $title; ?>" displayText="sharethis"></span>
  </div>
  <p>
    Abstimmung
    <?php
    if(!empty($field_poll_date)){
      $date_object = new DateObject($field_poll_date[0]['value'], new DateTimeZone($field_poll_date[0]['timezone_db']));
      print ' am '.date_format_date($date_object, 'custom', 'd.m.Y');
    }
    print ' im '.$field_parliament[0]['taxonomy_term']->name;
    ?>
  </p>

  <?php if($field_voted): ?>
  <div class="pw-voting">
    <ul class="clearfix push-bottom-s">
      <?php
      $block_result = module_invoke('pw_vote', 'block_view', 'final_result_short', array('nid' => $nid));
      print render($block_result['content']);
      ?>
    </ul>
  </div>
  <?php endif; ?>
  <div class="petition-list-image-wrapper img-outline">
    <a href="<?php print $node_url; ?>" title="zur Abstimmung">
      <?php print $themed_image; ?>
    </a>
    <?php if (!empty($field_teaser_image[0]['field_image_copyright']['und'][0]['value'])): ?>
      <div class="copyright">
        <?php print $field_teaser_image[0]['field_image_copyright']['und'][0]['value']; ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="pw-petition-list-contents">
    <?php print check_markup($body[0]['summary']); ?>
  </div>
  <a class="icon-poll" href="<?php print $node_url; ?>" title="zur Abstimmung">Details zur Abstimmung</a>
  <?php if (!empty($field_blogpost_blogtags)): ?>
    <p class="icon-taxonomy push-bottom-m">
      <?php print _pw_get_linked_terms($field_blogpost_blogtags); ?>
    </p>
  <?php endif; ?>
  <p class="comment-count push-bottom-m">
    <?php print format_plural($comment_count, '1 Kommentar', '@count Kommentare'); ?>
  </p>
</div>