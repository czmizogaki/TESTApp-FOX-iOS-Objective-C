#import <Foundation/Foundation.h>

/**
 * Object contains event definition.
 */
@interface FOXEvent : NSObject

/** @name Properties */

/**
 * LTV identifier from FOX
 */
@property (nonatomic, readonly) NSUInteger ltvId;

/**
 * client user identifier
 */
@property (nonatomic, copy, nullable) NSString* buid;

/**
 * customized key-value information
 */
@property (nonatomic, readonly, nullable) NSDictionary* extraInfo;

/**
 * name of event
 */
@property (nonatomic, readonly, nonnull)  NSString* eventName;

/**
 * value with the event
 */
@property (nonatomic) NSUInteger value;

/**
 * order id for item purchase event
 */
@property (nonatomic, copy, nullable)  NSString* orderId;

/**
 * SKU of the item
 */
@property (nonatomic, copy, nullable) NSString* sku;

/**
 * name of the item
 */
@property (nonatomic, copy, nullable) NSString* itemName;

/**
 * price of the item
 */
@property (nonatomic) double price;

/**
 * quantity of the item
 */
@property (nonatomic) NSUInteger quantity;

/**
 * currency for the price
 */
@property (nonatomic, copy, nullable) NSString* currency;

/**
 * customized information in JSON type for the event
 */
@property (nonatomic, copy, nullable) NSDictionary* eventInfo;


/** @name Initialize methods */

+(nullable instancetype) new __unavailable;
-(nullable instancetype) init __unavailable;

/**
 * init with event name
 * @param eventName event name
 */
-(nullable instancetype) initWithEventName:(nonnull NSString*) eventName;

/**
 * init wht event name and LTV id
 * @param eventName event name
 * @param ltvId LTV identifier from FOX
 */
-(nullable instancetype) initWithEventName:(nonnull NSString*) eventName andLtvId:(NSUInteger) ltvId NS_DESIGNATED_INITIALIZER;

/** @name Instance methods */

/**
 * add specified key-value info to extraInfo
 * @param value value
 * @param key key
 */
-(void) addExtraValue:(nonnull NSString*) value forKey:(nonnull NSString*) key;


/** @name Helper methods */

/**
 * helper method to make an event of purchase
 * @param eventName event name
 * @param ltvId LTV id from FOX
 * @param price price
 * @param currency currency
 */
+(nullable FOXEvent*) makePurchaseEventWithEventName:(nonnull NSString*) eventName
                                               ltvId:(NSUInteger) ltvId
                                               price:(double) price
                                            currency:(nullable NSString*) currency;

@end
