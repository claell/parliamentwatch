<li class="item vote <?php print $class_name; ?>">
  <a class="pw-arrow-box-trigger inline-block" href="/<?php print $path_profile; ?>" title="<?php print $firstname; ?> <?php print $lastname; ?> (<?php print $party; ?>)"></a>
  <div class="item-politician pw-arrow-box" style="left: -90000px;">
    <span class="icon-close light"></span>
    <h3>
      <?php print $firstname; ?> <?php print $lastname; ?> (<?php print $party; ?>)
    </h3>
    <p>
      <span class="medium">Position von <?php print $firstname; ?> <?php print $lastname; ?>: </span>
      <span class="vote <?php print $class_name; ?> block"><?php print $voting_behavior; ?></span>
    </p>
    <div class="float-left portrait-s">
      <a href="/<?php print $path_profile; ?>"><?php print $portrait; ?></a>
    </div>
    <?php if (strlen($statement) > 0): ?>
      <div class="statement">
        <div class="scrollbars-inner">
          <blockquote>
            <?php print check_markup($statement); ?>
          </blockquote></div>
      </div>
    <?php endif ?>
    <p class="path-profile">
      <a href="/<?php print $path_profile; ?>#pw_block_user_questionform" class="icon-politician">jetzt zur Position befragen</a>
    </p>
  </div>
</li>
