//
//  KarteUIWindow.h
//  Pods
//
//  Created by 中間亮彬 on 2017/10/21.
//
//

@import UIKit;

@class KarteOverlayViewController;

@interface KarteUIWindow : UIWindow
@property (nonatomic, strong) KarteOverlayViewController *overlayViewController;
- (instancetype)initWithTracker:(KarteTracker *)tracker url:(NSURL *)url;
- (void)handleAppViewWillAppear:(UIViewController *)vc;
- (void)handleAppViewDidAppear:(UIViewController *)vc;
- (void)handleAppViewWillDisappear:(UIViewController *)vc;
- (void)handleAppViewDidDisappear:(UIViewController *)vc;
- (void)show;
- (void)hide;
@end
