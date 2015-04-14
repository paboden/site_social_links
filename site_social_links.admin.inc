<?php

/**
 * Creates/returns a form to configure the block's variables.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function site_social_links_configure($form, &$form_state) {

  $form['#tree'] = TRUE;

  $site_social_links = variable_get('site_social_links', array());

  if (!empty($site_social_links)) {
    if (empty($form_state['num_icons'])) {
      $form_state['num_icons'] = count($site_social_links);
    }
  }

  if (empty($form_state['num_icons'])) {
    $form_state['num_icons'] = 1;
  }

  for ($i = 0; $i < $form_state['num_icons']; $i++) {

    $form['site_social_links'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Social icon ' . ($i + 1)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['site_social_links'][$i]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => isset($site_social_links[$i]['name']) ? $site_social_links[$i]['name'] : '',
    );
    $form['site_social_links'][$i]['display_name'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display Name'),
      '#default_value' => isset($site_social_links[$i]['display_name']) ? $site_social_links[$i]['display_name'] : FALSE,
    );
    $form['site_social_links'][$i]['url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#default_value' => isset($site_social_links[$i]['url']) ? $site_social_links[$i]['url'] : '',
    );
    $form['site_social_links'][$i]['target'] = array(
      '#type' => 'checkbox',
      '#title' => t('Open in new window'),
      '#default_value' => isset($site_social_links[$i]['target']) ? $site_social_links[$i]['target'] : FALSE,
    );
    $form['site_social_links'][$i]['class'] = array(
      '#type' => 'textfield',
      '#title' => t('Classes'),
      '#default_value' => isset($site_social_links[$i]['class']) ? $site_social_links[$i]['class'] : '',
    );

    variable_set('site_social_links', $site_social_links);
  }

  $form['add_social_icon'] = array(
    '#type' => 'submit',
    '#value' => t('Add another social icon'),
    '#submit' => array('site_social_links_add_icon'),
    '#disabled' => false,
  );

  if ($form_state['num_icons'] > 1) {
    $form['remove_social_icon'] = array(
      '#type' => 'submit',
      '#value' => t('Remove last social icon'),
      '#submit' => array('site_social_links_remove_icon'),
      '#limit_validation_errors' => array(),
    );
  }

  return system_settings_form($form);
}

/**
 * Submit handler for "Add another column" button().
 */
function site_social_links_add_icon($form, &$form_state) {
  $form_state['num_icons']++;

  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for "Add another column" button().
 */
function site_social_links_remove_icon($form, &$form_state) {
  if ($form_state['num_icons'] > 1) {
    $form_state['num_icons']--;
  }
  $form_state['rebuild'] = TRUE;
}