#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FOXEvent.h"

#pragma mark - APIs definition

/**
 * Option for method "onLaunchWithOption:"
 */
@interface FOXTrackOption : NSObject

/**
 * type of callback invoked after tracking finished
 */
typedef void (^FOXOnTrackFinished)();

/** @name Properties */

/**
 * should track enabled
 */
@property (nonatomic) BOOL optout;

/**
 * landing page to be redirected after tracking finished
 */
@property (nonatomic, nullable) NSString* redirectURL;

/**
 * client user identifier
 */
@property (nonatomic, nullable) NSString* buid;

/**
 * callback invoked after track is finished
 */
@property (nonatomic, copy, nullable) FOXOnTrackFinished onTrackFinished;

@end

/**
 * Main APIs
 */
@interface FOXTrack : NSObject

/** @name Tracking APIs */
#pragma mark - Tracking APIs
/**
 * launch event tracking by default.
 */
+(void) onLaunch;

/**
 * launch event tracking with indicated option
 * @param option indicated option
 */
+(void) onLaunchWithOption:(nonnull FOXTrackOption*) option;

/**
 * Receive the URL for re-engagement tracking.
 * Should be called within method UIApplicationDelegate -application:openUrl:sourceApplication:annotation
 * @param url URL includes customized URL scheme
 */
+(void) handleOpenURL:(nonnull NSURL*) url;

/**
 * Start session action
 */
+(void) startSession;

/**
 * Send action event
 * @param event tracking event to be sent
 */
+(void) sendEvent:(nonnull FOXEvent*) event;

/**
 * Get shared user info
 */
+(nullable NSDictionary*) getUserInfo;

/**
 * Set shared user info shared for all events
 * @param userInfo shared user info
 */
+(void) setUserInfo:(nonnull NSDictionary*) userInfo;

/**
 * Check whether install conversion has succeeded.
 */
+(BOOL) isConversionCompleted;

/**
 * Track event by external browser
 * @param redirectURL URL will be open by Safari Browser
 */
+(void) trackEventByBrowser:(nonnull NSString*) redirectURL;
@end


