<li class="total vote <?php print $class_name; ?>">
  <?php if($do_link): ?>
  <a rel="filter--<?php print $fraction; ?>--<?php print $voting_behavior; ?>" title="Details anzeigen" href="#pw_vote_positions">
    <?php print $sum; ?> <?php print $voting_behavior; ?>
  </a>
  <?php else: ?>
    <?php print $sum; ?> <?php print $voting_behavior; ?>
  <?php endif; ?>
</li>
