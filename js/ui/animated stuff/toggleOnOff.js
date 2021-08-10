import {$} from "/tools.js";


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
	box-shadow: inset 1mm 1mm 2mm rgba(0, 0, 0, 0.5);
	position:relative;
	top: 0;
	right: 0;
	overflow: hidden;
	font-size: 2.5mm;
	user-select: none;
}

.toggleOn
{
	box-shadow: inset 1mm 1mm 2mm rgba(0, 0, 0, 0.5);
	text-shadow: 1px 1px #000, 0px 1px #000;
	text-align: center;
	height: 2mm;
	width: 10mm;
	color: #fff;
	padding: 1mm;
	font-weight: bold
}
.toggleOff
{
	box-shadow: inset 1mm 1mm 2mm rgba(0, 0, 0, 0.5);
	text-shadow: 1px 1px #000, 0px 1px #000;
	text-align: center;
	background-color: #888;
	height: 2mm;
	width: 10mm;
	color: #fff;
	padding: 1mm;
	font-weight: bold

}

.toggleOnOff-On-Start
{
	position: absolute;
	top: 0;
	left: 0;
	ransform: translate(0, 0);
}
.toggleOnOff-On
{
	position: absolute;
	top: 0;
	left: 0;
	animation-name: turnon;
	animation-duration: 0.3s;
	ransform: translate(0, 0);
}
.toggleOnOff-Off-Start
{ 
	position: absolute;
	top: 0;
	left: 0;
	transform: translate(-50%, 0);
}
.toggleOnOff-Off
{ 
	position: absolute;
	top: 0;
	left: 0;
	animation-name: turnoff;
	animation-duration: 0.3s;
	transform: translate(-50%, 0);
}


@keyframes turnoff
{
	from {transform: translate(0, 0);}
	to {transform: translate(-50%, 0);}
}

@keyframes turnon
{
	from {transform: translate(-50%, 0);}
	to {transform: translate(0, 0);}
}
`;

const html = `
<span tieclass="parentclass" tieattributes="parentstyle:style" >
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
				if(at.class == "toggleOnOff-On" || at.class == "toggleOnOff-On-Start")
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
					if(at.class =="toggleOnOff-Off-Start")
					{
						if(at.hasafter)at.class = "toggleOnOff-On";
						else at.class = "toggleOnOff-On-Start";
					}
					else if(at.class == "toggleOnOff-Off") at.class = "toggleOnOff-On";
				}
				else
				{
					if(at.class =="toggleOnOff-On-Start")
					{
						 if(at.hasafter) at.class = "toggleOnOff-Off";
						 else at.class = "toggleOnOff-Off-Start";
					}
					else if(at.class == "toggleOnOff-On") at.class = "toggleOnOff-Off";
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
		onclick(e)
		{
			if(at.class == "toggleOnOff-On" || at.class == "toggleOnOff-On-Start")
			{
				at.class = "toggleOnOff-Off";
				if(at.attributes.onchange) at.attributes.onchange(false);
			}
			else
			{
				at.class = "toggleOnOff-On";
				if(at.attributes.onchange) at.attributes.onchange(true);
			}
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
