<div<?php print $attributes; ?>>
  <div<?php print $content_attributes; ?>>
    <a id="main-content"></a>
    <?php if ($messages): ?>
      <div id="messages"><?php print $messages; ?></div>
    <?php endif; ?>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
    <?php if ($title_hidden): ?><div class="element-invisible"><?php endif; ?>
    <h2 class="title" id="page-title"><?php print $title; ?></h2>
    <?php if ($title_hidden): ?></div><?php endif; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($tabs && !empty($tabs['#primary'])): ?><div class="tabs clearfix"><?php print render($tabs); ?></div><?php endif; ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print $content; ?>
    <?php if ($feed_icons): ?><div class="feed-icon clearfix"><?php print $feed_icons; ?></div><?php endif; ?>
  </div>
  
  
</div>

  <div id="newsletter-wrapper" class="hide-auto clear">

    <div class="container-12">
      <div id="newsletter-wrapper-inner" class="grid-12">
        <div id="newsletter-trigger">
        	<a href="#" title="schließen">schließen</a>
        </div>
        <img src="/sites/all/themes/custom/parliamentwatch/images/bg_newsletter.png" alt="bg_newsletter" class="float-left" />
        <div class="float-right">
        <?php
          $block = module_invoke('webform', 'block_view', 'client-block-10380');
          print render($block['content']);
        ?>
        </div>
      </div>
    </div>
  </div>