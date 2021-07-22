import {$q, $qa, $comp, $msgc, $fastpath} from "./tools.js";

const css = `
	.topMenuItem
	{
		display:inline-block;
		background-color: #444;
		border-bottom: 0.7mm solid #444;
		padding: 1mm 2mm;
		color: #fff;
		font-size: 3.5mm;
	}
	.topMenuItem.selected
	{
		background-color: #444;
		border-bottom: 0.7mm solid #aaa;
	}

`;
const html = `

	<span tieclass ="styleclass" tie = "text:innerHTML" tieevents="onclick:onclick">
	</span>

`;

function topMenuItem()
{
	
	var msgchandler = function(atid)
	{ 
		if(atid !== at.attributes.id)
		{
			at.attributes.selected=false;
		}
	};
	
	var isSelected = false;
	var groupField = "";
	var at = {
		
		attributes:
		{
			id: undefined,
			group: undefined,
			get text()
			{
				return at.text;
			},
			set text(v)
			{
				at.text = v;
			},
			
			get selected()
			{
				return isSelected;
			}, 
			set selected(value)
			{
				var v;
				if(typeof value ==="string") v = value ==="true";
				else v = value;
				if(isSelected != v)
				{ 
					
					isSelected = v;
					if(isSelected)
					{
						at.styleclass = "topMenuItem selected";
					}
					else
					{
						at.styleclass = "topMenuItem";
					}
					
				}
			},
			onclick: undefined
		},
		tracking: {},
		text: " ",
		styleclass: "topMenuItem",
		onclick(e)
		{
			if(!at.attributes.selected)
			{
				at.attributes.selected = true;
				$msgc.send(`${at.attributes.group} unselect all`, at.attributes.id);
				if(at.attributes.onclick) at.attributes.onclick(e);
			}
		},
		init()
		{
			$msgc.subscribe(`${at.attributes.group} unselect all`, msgchandler);
		},
		destruc()
		{
			console.log("topmenu destruct");
			$msgc.unsubscribe(`${at.attributes.group} unselect all`, msgchandler);
		}
		
		
	};
	
	return at;
	
}

topMenuItem.css = css;
topMenuItem.html = html;


$comp("topMenuItem", topMenuItem);
