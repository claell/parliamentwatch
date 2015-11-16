<article<?php print $attributes; ?>>
<?php
print theme('status_messages');
?>
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
<div class=" push-bottom-m">
  <?php if (!empty($field_blogpost_categories)): ?>
    <p class="icon-taxonomy">
      <?php print _pw_get_linked_terms($field_blogpost_categories); ?>
    </p>
  <?php endif; ?>
  <p class="comment-count">
    <?php print format_plural($comment_count, '1 Kommentar', '@count Kommentare'); ?>
  </p>
</div>
<?php
print render(field_view_field('node', $node, 'body', array('label' => 'hidden', 'type' => 'text_summary_or_trimmed')));
?>
<?php if($field_voted): ?>
  <?php
  // render voting behavior
  $block_voting_behavior = module_invoke('pw_vote', 'block_view', 'voting_behavior');
  print render($block_voting_behavior['content']);
  ?>
  <h3 id="pw_vote_positions">Wie haben Ihre Abgeordneten abgestimmt?</h3>
  <div class="compact-form push-bottom-l">
    <?
    // render search block
    $block_search = module_invoke('views', 'block_view', 'vote_search-block');
    print render($block_search['content']);
    ?>
  </div>
<?php endif; ?>

<h3>Hintergrund</h3>
<div class="managed-content clearfix push-bottom-l">
  <?php print render($content['body']);?>
</div>
<?php
// share buttons
$block = module_invoke('block', 'block_view', '12');
print render($block["content"]);
?>
<?php
  // render comments if there are any
$comments = render(comment_node_page_additions($node));
?>
<div id="comments" class="comment-wrapper">
  <?php if ($comment_count > 0): ?>
    <h3><?php print format_plural($comment_count, '1 Kommentar', '@count Kommentare'); ?> zu "<?php print $title; ?>"</h3>
  <?php endif; ?>
  <?php print $comments; ?>
</div>
</article>
