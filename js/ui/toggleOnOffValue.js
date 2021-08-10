
import {$} from "/tie.js";


const css = `


`;
const html = `
<span style = "display:inline-block; vertical-align: middle;">
	<comp tietype="toggleOnOff" tieobj="toggle" tieevents="onchange:onchange"></comp>
</span>
`;

function toggleOnOffValue()
{
	
	var at = 
	{
		attributes:
		{
			get state()
			{
				return at.toggle.state;
			},
			set state(v)
			{
				
				at.toggle.state = v;
			},
			get value()
			{
				return at.value;
			},
			set value(v)
			{
				at.value = v;
			},
			onchange:undefined,
			get color()
			{
				return at.toggle.color;
			},
			set color(v)
			{
				return at.toggle.color = v;
			},
			get class()
			{
				return at.toggle.class;
			},
			set class(v)
			{
				at.toggle.class = v;
			}
		},
		toggle:undefined,
		value: "",
		onchange(v)
		{
			if(at.attributes.onchange)at.attributes.onchange({value:at.value, state: at.toggle.state});
		},
		init()
		{
			
		}
		
	};
	return at;
}

toggleOnOffValue.css = css;
toggleOnOffValue.html = html;

$.comp("toggleOnOffValue", toggleOnOffValue);
