#import <Foundation/Foundation.h>

/**
 * Configuration for SDK, should be activited before any API is invoked.
 */
@interface FOXConfig : NSObject


#pragma mark - properties
#pragma mark -required
/** @name Properties required */

/**
 * application identifier from FOX
 */
@property (nonatomic, readonly, nonnull) NSString* appId;

/**
 * salt for digest from FOX
 */
@property (nonatomic, readonly, nullable) NSString* salt;

/**
 * application unique key from FOX
 */
@property (nonatomic, readonly, nullable) NSString* appKey;


#pragma mark -optional
/** @name Properties optional */

/**
 * specified server URL for conversion tracking
 */
@property (nonatomic, nullable) NSString* foxServerURL;

/**
 * specified server URL for event analytics
 */
@property (nonatomic, nullable) NSString* analyticsServerURL;

/**
 * enable debug mode to show debug log
 */
@property (nonatomic) BOOL debugMode;

/**
 * enable event tracking within UIWebView
 */
@property (nonatomic) BOOL webViewTrackingEnabled;


#pragma mark - init API
/** @name Initialize methods */

+(nullable instancetype) new __unavailable;

/**
 * configuration with required information
 * @param appId application identifier from FOX
 * @param salt salt for digest from FOX
 * @param appKey application unique key from FOX
 */
+(nullable FOXConfig*) configWithAppId:(NSUInteger) appId salt:(nonnull NSString*) salt appKey:(nonnull NSString*) appKey;

-(nullable instancetype) init __unavailable;


#pragma mark - optional API
/** @name Instance methods */

/**
 * set specified server URL for conversion tracking
 * @param url specified server URL
 */
-(nonnull FOXConfig*) withFOXServerURL:(nonnull NSString*) url;

/**
 * set specified server URL for event analytics
 * @param url specified server URL
 */
-(nonnull FOXConfig*) withAnalyticsServerURL:(nonnull NSString*) url;

/**
 * enable debug moe
 */
-(nonnull FOXConfig*) withDebugMode;

/**
 * enable event tracking with UIWebView
 */
-(nonnull FOXConfig*) withWebViewTrackingEnabled;


#pragma mark - activate

/** @name Activate configuration */

/**
 * reflect the configuration on application
 * !only effects when being invoked for first time.
 */
-(void) activate;

@end
