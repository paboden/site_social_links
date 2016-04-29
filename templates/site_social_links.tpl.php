<?php

/**
 * Displays the social media icon block.
 */
?>
<div class="social-links--container">
  <?php foreach ($social_icons as $icon) : ?>
    <a href="http://<?php print $icon['url']; ?>" <?php if ($icon['target']) : print 'target="_blank"'; endif;?> class="social-icons--link">
      <span class="social-links fa <?php print $icon['class']; ?>">
        <?php if ($icon['display_name']) : print $icon['name']; endif;?>
      </span>
    </a>
  <?php endforeach;?>
</div>
