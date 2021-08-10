import {$} from "/tie.js";

const css = `
	.Button
	{
		margin: 0 0.5mm 0.5mm 0;
		border-width: 0.7mm;
		border-style: solid;
		padding: 0.5mm;
		border-radius: 2mm;
		box-shadow: 0 0 3mm;
		user-select: none;
		background-color: #444;
		display: inline-block;
		text-shadow: 1px 1px 1px #000;
	}
	
	.Button:active
	{
		margin: 0.5mm 0 0 0.5mm;
		box-shadow: 0 0 0 rgba(0, 0, 0, 0);
		user-select: none;
	}



`;

const html = `
<span class="Button" tie = "bordercolor:style.borderColor, color:style.color"   tieattributes="style:style" tieevents="onclick:onclick" tieinner>
	
</span>
`;


function button()
{
	var at = 
	{
		attributes:
		{
			get color()
			{
				return at.color;
			},
			set color(v)
			{
				at.color = v;
				at.bordercolor = v;
				
			},
			get class()
			{
				return "Button " + _class;
			},
			set class(v)
			{
				at.class = "Button " + _class;
			},
			get style()
			{
				return at.style;
			},
			set style(v)
			{
				var color = at.color;
				at.style = v;
				at.color = color;
				at.bordercolor = color;
			},
			onclick: undefined
		},
		bordercolor: "#fff",
		color: "#fff",
		style: "",
		onclick(e)
		{
			console.log("eee");
			console.log(at.attributes.onclick);
			if(at.attributes.onclick) at.attributes.onclick(e);
		},
		beforeinit()
		{
			
			console.log("button");
			console.log(at);
			
		}
		
	};
	return at;
}

button.css = css;
button.html = html;



$.comp("button", button);







