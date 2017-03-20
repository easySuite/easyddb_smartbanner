/**
 * Created by Max on 15.03.2017.
 */

(function ($) {
  $(document).ready(function () {
    console.log(Drupal.settings.easyddb_smartbanner);
    new SmartBanner({
      daysHidden: Drupal.settings.easyddb_smartbanner.days_hidden,   // days to hide banner after close button is clicked (defaults to 15)
      daysReminder: Drupal.settings.easyddb_smartbanner.days_reminder, // days to hide banner after "VIEW" button is clicked (defaults to 90)
      appStoreLanguage: Drupal.settings.easyddb_smartbanner.app_store_language, // language code for the App Store (defaults to user's browser language)
      title: Drupal.settings.easyddb_smartbanner.app_title,
      author: Drupal.settings.easyddb_smartbanner.app_author,
      button: Drupal.settings.easyddb_smartbanner.button_name,
      store: {
        ios: Drupal.settings.easyddb_smartbanner.apple.description,
        android: Drupal.settings.easyddb_smartbanner.android.description,
        windows: Drupal.settings.easyddb_smartbanner.windows.description
      },
      price: {
        ios: Drupal.settings.easyddb_smartbanner.apple.price,
        android: Drupal.settings.easyddb_smartbanner.android.price,
        windows: Drupal.settings.easyddb_smartbanner.windows.price
      }
    });
  });
})(jQuery);
