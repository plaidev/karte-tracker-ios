#import "AppDelegate.h"
#import <KarteTracker/KarteTracker.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

// api_key of KARTE
static NSString *const kAppKey = @"xWveWk7vG3ERsNXFRk9QcMEtdRXpIs70";

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  [FIRApp configure];
  
  KarteTrackerShowLog(YES);
  [KarteTracker setupWithAppKey:kAppKey config:@{}];
  
  [FIRMessaging messaging].delegate = self;
  if (floor(NSFoundationVersionNumber) <= NSFoundationVersionNumber_iOS_9_x_Max) {
    UIUserNotificationType allNotificationTypes = UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge;
    UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:allNotificationTypes categories:nil];
    [application registerUserNotificationSettings:settings];
  } else {
    // iOS 10 or later
#if defined(__IPHONE_10_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
    // For iOS 10 display notification (sent via APNS)
    [UNUserNotificationCenter currentNotificationCenter].delegate = self;
    UNAuthorizationOptions authOptions = UNAuthorizationOptionAlert | UNAuthorizationOptionSound | UNAuthorizationOptionBadge;
    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:authOptions completionHandler:^(BOOL granted, NSError * _Nullable error) {
    }];
#endif
  }
  
  [application registerForRemoteNotifications];
  
  return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
  // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
  // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
  // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
  // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
  // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken
{
  [FIRMessaging messaging].APNSToken = deviceToken;
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(nonnull NSError *)error
{
  NSLog(@"device token error: %@", [error description]);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo
{
  NSLog(@"push info: %@", [userInfo description]);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler
{
  NSLog(@"receive %@", [userInfo description]);
  
  switch (application.applicationState) {
    case UIApplicationStateActive:
    case UIApplicationStateInactive:
      if (![KarteRemoteNotificationHandler handleRemoteNotification:userInfo]) {
        // Did not handle URL or DeepLink.
      }
      break;
      
    case UIApplicationStateBackground:
      break;
  }
  
  completionHandler(UIBackgroundFetchResultNewData);
}

#pragma mark - UNUserNotificationDelegate
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler
API_AVAILABLE(ios(10.0)) {
  completionHandler(UNNotificationPresentationOptionNone);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler
API_AVAILABLE(ios(10.0)) {
  NSLog(@"userNotificationCenter received notification");
  
  NSDictionary *userInfo = response.notification.request.content.userInfo;
  if (![KarteRemoteNotificationHandler handleRemoteNotification:userInfo]) {
    // SDK側でメッセージのハンドルができない場合の処理を記述する
  }
  
  completionHandler();
}

#pragma mark - Firebase messaging delegate
- (void)messaging:(FIRMessaging *)messaging didReceiveRegistrationToken:(NSString *)fcmToken
{
  [[KarteTracker sharedTracker] registerFCMToken:fcmToken];
}

- (void)messaging:(FIRMessaging *)messaging didReceiveMessage:(FIRMessagingRemoteMessage *)remoteMessage
{
}

@end
