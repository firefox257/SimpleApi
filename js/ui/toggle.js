import {$} from "/tie.js";


const css = `
.toggleOuter.enabled
{
	display:inline-block;
	border-radius: 3mm;
	height: 4mm;
	width: 13mm;
	background-color: #0b0;
	color: #fff;
	padding: 1mm;
	text-align: right;
}
.toggleOuter.disabled
{
	display:inline-block;
	border-radius: 3mm;
	height: 4mm;
	width: 13mm;
	background-color: #bbb;
	color: #fff;
	padding: 1mm;
	text-align: left;
}
.toggleButton
{
	border-radius:2mm;
	width: 4mm;
	height: 4mm;
	background-color: #fff;
	float:left;
}
`;

const html = `
<span class="toggleOuter enabled" >
<span tie="text:innerHTML"></span> <span class="toggleButton">&nbsp</span>
</span>
`;

function toggle()
{
	var at = 
	{
		text: "ON"
		
	};
	return at;
}

toggle.css = css;
toggle.html = html;
$.comp("toggle", toggle);
