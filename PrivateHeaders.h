#define VARIANT_LOCKSCREEN 0
#define VARIANT_HOMESCREEN 1

@interface SBWallpaperController : NSObject
+ (instancetype)sharedInstance;

- (void)setLockscreenOnlyWallpaperAlpha:(float)alpha;
- (id)_newWallpaperViewForProcedural:(id)proceduralWallpaper orImage:(UIImage *)image;
- (id)_newWallpaperViewForProcedural:(id)proceduralWallpaper orImage:(UIImage *)image forVariant:(int)variant; //iOS 7.1
- (id)_clearWallpaperView:(id *)wallpaperView;
- (void)_handleWallpaperChangedForVariant:(NSUInteger)variant;
- (void)_updateSeparateWallpaper;
- (void)_updateSharedWallpaper;
- (void)_reconfigureBlurViewsForVariant:(NSUInteger)variant;
- (void)_updateBlurImagesForVariant:(NSUInteger)variant;
@end

@interface NowPlayingArtPluginController : NSObject
@end

@interface SBFStaticWallpaperView : UIView
- (instancetype)initWithFrame:(CGRect)frame wallpaperImage:(UIImage *)wallpaperImage;
- (UIImageView *)contentView;
- (void)setVariant:(NSUInteger)variant;
- (void)setZoomFactor:(float)zoomFactor;
@end

@interface _SBFakeBlurView : UIView
+ (UIImage *)_imageForStyle:(int *)style withSource:(SBFStaticWallpaperView *)source;
- (void)updateImageWithSource:(id)source;
- (void)reconfigureWithSource:(id)source;
@end

@interface SBMediaController : NSObject
+ (instancetype)sharedInstance;

- (id)_nowPlayingInfo;
- (UIImage *)artwork;
- (NSUInteger)trackUniqueIdentifier;
- (BOOL)isPlaying;
@end

@interface SBUIController : NSObject
+ (instancetype)sharedInstance;

- (void)setLockscreenArtworkImage:(UIImage *)artworkImage;
- (void)updateLockscreenArtwork;
- (void)blurryArtworkPreferencesChanged;
@end

@interface _NowPlayingArtView : UIView
- (UIImageView *)artworkView;
@end

@interface SBLockScreenScrollView : UIScrollView
@end
