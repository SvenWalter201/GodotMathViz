extends OptionButton


var init = false


func _ready():
	add_item("Wave", 0)
	add_item("DoubleWave", 1)
	add_item("TrippleWave", 2)
	add_item("Ripple", 3)
	add_item("Sphere", 4)
	add_item("Torus", 5)
	selected = 0

# func _process(delta):
#	if !init:
#
#		emit_signal("item_selected")
#		init = true
