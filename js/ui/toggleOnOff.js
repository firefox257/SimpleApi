import {$} from "/tie.js";


const css = `
.toggleOuter
{
	display:inline-block;
	border-radius: 3mm;
	height: 5mm;
	width: 10mm;
	color: #fff;
	padding: 0;
	text-align: right;
	box-shadow: 0 0 0;
	position:relative;
	top: 0;
	right: 0;
	overflow: hidden;
	font-size: 2.5mm;
	user-select: none;
	border: 0.3mm solid #888;
}

.toggleOn
{
	box-shadow: inset 1mm 1mm 2mm rgba(0, 0, 0, 0.5);
	
	text-align: center;
	height: 2mm;
	width: 10mm;
	color: #000;
	padding: 1mm;
	font-weight: bold
}
.toggleOff
{
	box-shadow: inset 1mm 1mm 2mm rgba(0, 0, 0, 0.5);
	text-shadow: 1px 1px #000, 0px 1px #000;
	text-align: center;
	background-color: #444;
	height: 2mm;
	width: 10mm;
	color: #888;
	padding: 1mm;
	font-weight: bold

}

.toggleOnOff-On
{
	position: absolute;
	top: 0;
	left: 0;
	ransform: translate(0, 0);
}

.toggleOnOff-Off
{ 
	position: absolute;
	top: 0;
	left: 0;
	transform: translate(-50%, 0);
}



`;

const html = `
<span tieclass="parentclass" tieattributes="parentstyle:style" tie="boxshadow:style.boxShadow, border:style.border ">
	<table cellspacing="0" cellpadding="0" style="width: 20mm;" tieclass="class" tieevents="onclick:onclick">
		<tr>
			<td class = "toggleOn" style="width:10mm" tie="color:style.backgroundColor">
				ON
			</td>
			<td class="toggleOff" style="width:10mm">
				OFF
			</td>
		</tr>
	</table>
</span>
`;

function toggleOnOff()
{
	var at = 
	{
		attributes:
		{
			get state()
			{
				if(at.class == "toggleOnOff-On")
				{
					return true;
				}
				else
				{
					return false;
				}
			},
			set state(v)
			{
				if(v == true)
				{
					at.class = "toggleOnOff-On";
					at.boxshadow = "0 0 2mm " + at.color;
					at.border = "0.3mm solid " + at.color;
				}
				else
				{
					at.class = "toggleOnOff-Off";
					at.boxshadow = "0 0 0";
					at.border = "0.3mm solid #888";
				}
			},
			onchange:undefined,
			hasafter:false,
			get color()
			{
				return at.color;
			},
			set color(v)
			{
				at.color = v;
				at.attributes.state = at.attributes.state;
			}, 
			get class()
			{
				return at.parentclass;
			},
			set class(v)
			{
				at.parentclass = "toggleOuter " + v;
			}, 
			get style()
			{
				return at.style;
			},
			set style(v)
			{
				at.style = v;
			}
			
		},//end attributes
		parentclass: "toggleOuter",
		parrentstyle: "",
		class: "toggleOnOff-Off-Start",
		color: "#fa0",
		boxshadow: "0 0 0",
		border: "0.3mm solid #888",
		onclick(e)
		{
			if(at.attributes.state) at.attributes.state = 0;
			else at.attributes.state = 1;
			if(at.attributes.onchange) at.attributes.onchange(at.attributes.state);
			/*if(at.class == "toggleOnOff-On" || at.class == "toggleOnOff-On-Start")
			{
				at.class = "toggleOnOff-Off";
				if(at.attributes.onchange) at.attributes.onchange(false);
			}
			else
			{
				at.class = "toggleOnOff-On";
				if(at.attributes.onchange) at.attributes.onchange(true);
			}*/
		},
		init()
		{
			
		}, 
		afterinit()
		{
			at.hasafter = true;
		}
		
	};
	return at;
}

toggleOnOff.css = css;
toggleOnOff.html = html;
$.comp("toggleOnOff", toggleOnOff);
