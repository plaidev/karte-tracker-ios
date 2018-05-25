#
# Be sure to run `pod lib lint KarteTracker.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'KarteTracker'
  s.version          = '1.2.0'
  s.summary          = 'KARTE SDK for iOS'
  s.homepage         = 'https://karte.io/'
  s.author           = { 'Plaid' => 'dev.share@plaid.co.jp' }
  s.source           = { :git => 'https://github.com/plaidev/karte-tracker-ios.git', :tag => "v#{s.version}" }
  s.social_media_url = 'https://twitter.com/karte_io'
  s.documentation_url = 'https://dash.readme.io/project/karteio/v0.1/docs/ios'
  s.platform     = :ios
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
    Copyright© Plaid Inc., All Rights Reserved.
    LICENSE
  }
  s.ios.deployment_target = '8.0'
  s.vendored_frameworks = 'KarteTracker.framework'
  s.compiler_flags = '-ObjC'
  s.requires_arc = true
  s.frameworks = [
    "WebKit"
  ]
end
