
import {$} from "/tie.js";
import {} from "./ui/ui.js";

const css = `
body
{
	font-size: 3.5mm;
	background-color: #333;
	color: #bbb;
}
.full
{
	position: absolute;
	top:0;
	left: 0;
	bottom: 0;
	right: 0;
	width: 100%;
	height: 100%;
}


block
{
	padding:0;
	margin:0;
	display:inline-block;
	background-color: rgba(0, 0, 0, 0);
}
`;

const html = `
<div class ="full">
<br/>


<br/>
<br/>
<comp tietype="toggleOnOffValue" state="0" value = "abc" tieevents="onchange:onchange" color="#0b0"></comp>
<comp tietype="toggleOnOffValue" state="0" value = "bcd" tieevents="onchange:onchange"></comp>
<comp tietype="toggleOnOffValue" state="0" value = "cde" tieevents="onchange:onchange"></comp>
<br/>

<br/>
<span tie="title:innerHTML"></span><br/>
<comp tietype ="toggleOnOffGroup" tieevents="onchange:onchange" color ="#0f0">
{
	"option 1": 
	{
		state: 1,
		value: "abc"
	},
	"option 2":
	{
		state: 0,
		value: "bcd"
	},
	"option 3":
	{
		state: 0,
		value: "ddd"
	},
	"option 4":
	{
		state: 0,
		value: "ddd1"
	}
}

</comp>

<br/>
<br/>


<comp tietype="checkbox" color="#00ff88" checked="0" tieevents="onchange1:onchange"></comp>

<comp tietype="modal" show="0" color="#999" tieobj="atmodal">
<table>
	<tr>
		<td colspan="2">
		Hi there <comp tietype="checkbox" color="#ff3300" checked="0" tieevents="onchange:onchange"></comp>
		</td>
	</tr>
	<tr>
		<td>
			<comp tietype="button" color = "#00ffaa" tieevents="onclick1:onclick">Ok</comp>
		</td>
		<td>
			
		</td>
	</tr>
</table>
</comp>

</div>

`;

var at = 
{
	onchange(v)
	{
		at.title = v;
		if(v == undefined) at.title = "";
		console.log(v);
	}, 
	onchange1(v)
	{
		at.atmodal.show = v;
	},
	onclick1(e)
	{
			console.log("ehre33");
		at.atmodal.show = 0;
	}
};

function mainappfunc()
{
	return at;
}

mainappfunc.css = css;
mainappfunc.html = html;


$.comp("mainapp", mainappfunc);



