#
# Be sure to run `pod lib lint KarteTracker.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name                    = 'KarteTracker'
  s.version                 = '1.5.1'
  s.summary                 = 'KARTE SDK for iOS'
  s.homepage                = 'https://karte.io/'
  s.author                  = { 'Plaid' => 'dev.share@plaid.co.jp' }
  s.social_media_url        = 'https://twitter.com/karte_io'
  s.documentation_url       = 'https://karteio.readme.io/docs/ios'
  s.license                 = {
    :type => 'Commercial',
    :text => 'Copyright© Plaid Inc., All Rights Reserved.'
  }
  s.platform                = :ios
  s.requires_arc            = true
  s.ios.deployment_target   = '8.0'

  if ENV['RELEASE'] == 'true' then
    s.source                = { :git => 'https://github.com/plaidev/karte-tracker-ios.git', :tag => "v#{s.version}" }
    s.vendored_frameworks   = 'KarteTracker.embeddedframework/KarteTracker.framework'
    s.resources             = 'KarteTracker.embeddedframework/Resources/KarteTrackerResources.bundle'
    s.compiler_flags        = '-ObjC'
    s.ios.frameworks        = 'WebKit'
    s.ios.weak_frameworks   = 'AdSupport'
  else
    s.source                = { :git => 'https://github.com/plaidev/tracker-ios.git', :tag => 'v0.0.0' }
    s.source_files          = 'KarteTracker/Classes/**/*'
    s.public_header_files   = 'KarteTracker/Classes/*.h'
    s.private_header_files  = 'KarteTracker/Classes/Private/*.h'
    s.resource_bundles      = { 'KarteTrackerResources' => 'KarteTracker/Assets/*' }
    s.pod_target_xcconfig   = { 'OTHER_CFLAGS' => '-fembed-bitcode' }
  end
end
