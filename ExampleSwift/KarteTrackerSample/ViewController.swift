import UIKit
import KarteTracker

class ViewController: UIViewController {
    @IBOutlet weak var userIdField: UITextField!
    @IBOutlet weak var viewNameField: UITextField!

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func tapIdentify(sender: Any) {
        let userId = userIdField.text ?? ""
        KarteTracker.shared.identify(["user_id": userId])
    }
    
    @IBAction func tapSendView(sender: Any) {
        let viewName = viewNameField.text ?? ""
        KarteTracker.shared.view(viewName)
    }
    
    @IBAction func tapSendBuy(sender: Any) {
        KarteTracker.shared.track("buy", values: ["revenue": 100])
    }
}
