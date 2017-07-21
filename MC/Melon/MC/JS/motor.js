src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"
type="text/javascript"
	let duration = 2;
	function up() {
		$.ajax({
				url: `/game/move_up/${duration}`,
				async: false,
				success: function() {
						console.log("Done:", arguments)
				}
		});
	};

	function down() {
			$.ajax({
				url: `/game/move_down/${duration}`,
				async: false,
				success: function() {
						console.log("Done:", arguments)
				}
		});
	}

	function submit() {
			const data = {
				lenght_going_up: $('#lenght_going_up').val(),
				lenght_going_down: $('#lenght_going_down').val(),
			}
			$.ajax({
				method: 'POST',
				url: `/game/calibration/${duration}`,
				data: JSON.stringify(data),
				contentType: 'application/json',
				dataType: 'json',
				success: function() {
					console.log('Updated:', arguments)
				}
			})
			$.ajax({
				method: 'POST',
				url: '/game/rope_lenght/',
				data: JSON.stringify({'rope_lenght':$('#rope_lenght').val()}),
				contentType: 'application/json',
				dataType: 'json',
				success: function() {
					console.log('Updated:', arguments)
				}
			})
			
	}
