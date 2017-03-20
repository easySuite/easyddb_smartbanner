<?php
/**
 * @file
 *  Administration config form.
 */

/**
 * Module settings form.
 *
 * @param $form
 * @param $form_state
 */
function easyddb_smartbanner_settings_form($form, $form_state) {
  $configs = variable_get('smartbanner_config', array());

  $form['#tree'] = TRUE;

  $form['smartbanner']['base_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Base settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['smartbanner']['base_config']['days_hidden'] = array(
    '#type' => 'textfield',
    '#title' => t('Days hidden'),
    '#description' => t('Days to hide banner after close button clicked.'),
    '#default_value' => ($configs['base_config']['days_hidden']) ? $configs['base_config']['days_hidden'] : 15,
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['smartbanner']['base_config']['days_reminder'] = array(
    '#type' => 'textfield',
    '#title' => t('Days hidden'),
    '#description' => t('Days to hide banner after VIEW button is clicked.'),
    '#default_value' => ($configs['base_config']['days_reminder']) ? $configs['base_config']['days_reminder'] : 90,
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['smartbanner']['base_config']['app_store_language'] = array(
    '#type' => 'select',
    '#title' => t('iTunes store language'),
    '#description' => t('Select language for iTunes store'),
    '#options' => array(
      'en' => t('En'),
      'dk' => t('Dk'),
    ),
    '#default_value' => ($configs['base_config']['app_store_language']) ? $configs['base_config']['app_store_language'] : 'en',
  );

  $form['smartbanner']['base_config']['app_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Application title.'),
    '#default_value' => ($configs['base_config']['app_title']) ? $configs['base_config']['app_title'] : '',
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['smartbanner']['base_config']['app_author'] = array(
    '#type' => 'textfield',
    '#title' => t('Author'),
    '#description' => t('Application author.'),
    '#default_value' => ($configs['base_config']['app_author']) ? $configs['base_config']['app_author'] : '',
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['smartbanner']['base_config']['button_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Button value'),
    '#description' => t('Value for button.'),
    '#default_value' => ($configs['base_config']['button_name']) ? $configs['base_config']['button_name'] : '',
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['smartbanner']['base_config']['app_icon'] = array(
    '#title' => t('Application icon'),
    '#type' => 'managed_file',
    '#upload_location' => 'public://easyddb_smartbanner/',
    '#default_value' => EASYDDB_SMARTBANNER_MODULE_PATH . '/icon.png',
    '#upload_validators' => array(
      'file_validate_extensions' => array('png'),
      // Pass the maximum file size in bytes
      'file_validate_size' => array(1000000),
    ),
  );

  $os = array(
    'apple' => 'Apple',
    'android' => 'Android',
  );

  // Configuration for Apple and Android.
  foreach ($os as $os_mach_name => $os_name) {
    $os_config = $os_mach_name . '_app_config';

    $form['smartbanner']['app_configs'][$os_config] = array(
      '#type' => 'fieldset',
      '#title' => t("{$os_name} application configuration"),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['smartbanner']['app_configs'][$os_config]['app_enabled'] = array(
      '#type' => 'checkbox',
      '#title' => t("Enable {$os_name} app banner."),
      '#default_value' => ($configs['app_configs'][$os_config]['app_enabled'])
        ? $configs['app_configs'][$os_config]['app_enabled']
        : '',
    );

    $form['smartbanner']['app_configs'][$os_config]['app_id'] = array(
      '#type' => 'textfield',
      '#title' => t("{$os_name} app id"),
      '#size' => 30,
      '#maxlength' => 30,
      '#required' => FALSE,
      '#default_value' => ($configs['app_configs'][$os_config]['app_id'])
        ? $configs['app_configs'][$os_config]['app_id']
        : '',
    );

    $form['smartbanner']['app_configs'][$os_config]['app_price'] = array(
      '#type' => 'textfield',
      '#title' => t("{$os_name} app price"),
      '#size' => 30,
      '#maxlength' => 30,
      '#required' => FALSE,
      '#default_value' => ($configs['app_configs'][$os_config]['app_price'])
        ? $configs['app_configs'][$os_config]['app_price']
        : '',
    );

    $form['smartbanner']['app_configs'][$os_config]['app_description'] = array(
      '#type' => 'textfield',
      '#title' => t("{$os_name} app description"),
      '#size' => 60,
      '#maxlength' => 255,
      '#required' => FALSE,
      '#default_value' => ($configs['app_configs'][$os_config]['app_description'])
        ? $configs['app_configs'][$os_config]['app_description']
        : '',
    );
  }

  // Configuration for windows.
  $os_config = 'windows_app_config';

  $form['smartbanner']['app_configs'][$os_config] = array(
    '#type' => 'fieldset',
    '#title' => t("Windows application configuration"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['smartbanner']['app_configs'][$os_config]['app_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t("Enable Windows app banner."),
    '#default_value' => ($configs['app_configs'][$os_config]['app_enabled'])
      ? $configs['app_configs'][$os_config]['app_enabled']
      : '',
  );

  $form['smartbanner']['app_configs'][$os_config]['app_id'] = array(
    '#type' => 'textfield',
    '#title' => t("Windows app id"),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => FALSE,
    '#default_value' => ($configs['app_configs'][$os_config]['app_id'])
      ? $configs['app_configs'][$os_config]['app_id']
      : '',
  );

  $form['smartbanner']['app_configs'][$os_config]['package'] = array(
    '#type' => 'textfield',
    '#title' => t("Windows package name"),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => FALSE,
    '#default_value' => ($configs['app_configs'][$os_config]['package'])
      ? $configs['app_configs'][$os_config]['package']
      : '',
  );

  $form['smartbanner']['app_configs'][$os_config]['app_price'] = array(
    '#type' => 'textfield',
    '#title' => t("Windows app price"),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => FALSE,
    '#default_value' => ($configs['app_configs'][$os_config]['app_price'])
      ? $configs['app_configs'][$os_config]['app_price']
      : '',
  );

  $form['smartbanner']['app_configs'][$os_config]['app_description'] = array(
    '#type' => 'textfield',
    '#title' => t("Windows app description"),
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => FALSE,
    '#default_value' => ($configs['app_configs'][$os_config]['app_description'])
      ? $configs['app_configs'][$os_config]['app_description']
      : '',
  );

  $form['#submit'] = array('easyddb_smartbanner_settings_form_submit');

  return system_settings_form($form);
}

function easyddb_smartbanner_settings_form_submit($form, &$form_state) {
  $values = $form_state['values']['smartbanner'];
//dump($values);
//exit;
  variable_set('smartbanner_config', $values);
}
