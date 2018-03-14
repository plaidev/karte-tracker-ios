//
//  BasicViewController.h
//  KarteTracker
//
#import "KarteTracker.h"

@import UIKit;

@interface KarteOverlayViewController : UIViewController<UITextFieldDelegate, UIWebViewDelegate, KarteTrackerDelegate>
@property UIWebView *webView;
@property NSURL* overlayViewUrl;

- (void)resetPageState;
@end
