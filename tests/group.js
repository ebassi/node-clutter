var clutter = require('../index');

if (clutter.init() != clutter.INIT_SUCCESS) {
	console.log("Failed to initialize clutter.");
	process.exit();
}

/* Create a new stage */
var stage = new clutter.Stage();
stage.setTitle('Group');
stage.resize(500, 500);
stage.setColor(0, 0, 0, 255);
stage.on(clutter.EVENT_DESTROY, function() {
	clutter.quit();
});
stage.show();

/* Create a group */
var group = new clutter.Group;
stage.add(group);

var texture1 = new clutter.Texture;
texture1.loadFile('fred.jpg');
texture1.setPosition(100, 100);
texture1.rotate(clutter.Y_AXIS, 45, 0, 0, 0);
group.add(texture1);

var texture2 = new clutter.Texture;
texture2.loadFile('fred.jpg');
texture2.setPosition(100, 200);
texture2.rotate(90, clutter.GRAVITY_CENTER);
group.add(texture2);

/* Move group */
group.setPosition(-100, -100);

clutter.main();
