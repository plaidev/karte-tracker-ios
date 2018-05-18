#import <UIKit/UIKit.h>
@import UserNotifications;
@import Firebase;

@interface AppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate, FIRMessagingDelegate>
@property (strong, nonatomic) UIWindow *window;

@end
