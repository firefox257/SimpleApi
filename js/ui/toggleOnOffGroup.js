/*
example
<comp tietype ="toggleOnOffGroup" tieevents="onchange:onchange" color ="#0f0">
{
	"option 1": 
	{
		state: 0,
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
	}
}

</comp>


*/




import {$} from "/tie.js";

const css = `



`;
const html = `
<block tieclass ="class" tieattributes="style:style">
	<span style="display:inline-block" tieinnerjson="code" tiedom="atdom"  >
	</span>
</block>
`;




function toggleOnOffGroup()
{
	
	var at = 
	{
		attributes:
		{
			get value()
			{
				return at.value;
			},
			set value(v)
			{
				for(var i = 0; i < at.items.length; i++)
				{
					var ii = at.items[i];
					if(ii.value != value) ii.state = 1;
				}
				at.value = v;
			}, 
			get class()
			{
				return at.class;
			},
			set class(v)
			{
				at.class = v;
			},
			get style()
			{
				return at.style;
			}, 
			set style(v)
			{
				at.style = v;
			},
			get color()
			{
				return at.color();
			},
			set color(v)
			{
				for(var i = 0; i < at.items.length; i++)
				{
					var item = at.items[i];
					item.color = v;
				}
				at.color = v;
			}
			
		},
		atdom: undefined,
		value: undefined,
		code: undefined,
		class: "",
		style: "",
		color: "#fa0",
		onchange(item)
		{
			var checkalloff = true;
			if(item.state)
			{
				
				for(var i = 0; i < at.items.length; i++)
				{
					
					var ii = at.items[i];
					
					if(ii.value != item.value) ii.state = 0;
					if(ii.state)
					{
						 checkalloff = false;
					 }
				}
			}
			
			if(checkalloff)
			{
				at.value = undefined;
			}
			else
			{
				at.value = item.value;
			}
			if(at.attributes.onchange) at.attributes.onchange(at.value);
		},
		items:[],
		set additem(v)
		{
			at.items.push(v);
		},
		init()
		{
			for(var i in at.code)
			{
				var item = at.code[i];
				var html = `
				<div>
					${i} <comp tietype="toggleOnOffValue" value = "${item.value}" state= "${item.state}" tieevents="onchange:onchange" tieobj="additem" color="${at.color}"></comp>
				</div>
				
				`;
				$.append(at, at.atdom,html);
				if(item.state) at.value = item.value;
			}
		}
	};
	return at;
}

toggleOnOffGroup.css = css;
toggleOnOffGroup.html = html;

$.comp("toggleOnOffGroup", toggleOnOffGroup);
