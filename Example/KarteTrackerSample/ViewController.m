#import "ViewController.h"
#import <KarteTracker/KarteTracker.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *userIdField;
@property (weak, nonatomic) IBOutlet UITextField *viewNameField;

@end

@implementation ViewController

- (void)viewDidLoad
{
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}
- (IBAction)clickedIdentify:(id)sender
{
  [[KarteTracker sharedTracker] identify:@{@"user_id": self.userIdField.text}];
}

- (IBAction)clickedView:(id)sender
{
  [[KarteTracker sharedTracker] view: self.viewNameField.text];
}

- (IBAction)clickedBuy:(id)sender
{
  [[KarteTracker sharedTracker] track:@"buy" values:@{@"revenue": @100}];
}

@end
