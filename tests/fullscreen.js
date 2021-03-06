var clutter = require('../index');

if (clutter.init() != clutter.INIT_SUCCESS) {
	console.log("Failed to initialize clutter.");
	process.exit();
}

/* Create a new stage */
var stage = new clutter.Stage();
stage.setTitle('Fullscreen');
stage.setColor(0, 0, 0, 255);
stage.fullscreen(true);
stage.on(clutter.EVENT_DESTROY, function() {
	clutter.quit();
});
stage.show();

clutter.main();
