import {$} from "/tie.js";
import {colors} from "/ui/colors.js";
const css = `

.modalfull
{
	position: absolute;
	top: 0;
	bottom: 0;
	left: 0;
	right: 0;
	width: 100%;
	height: 100%;
	background-color: rgba(0, 0, 0, 0.6);
	display: block;
	z-index: 100000;
}

.modalframe
{
	position: absolute;
	top: 50%;
	left: 50%;
	transform: translate(-50%, -50%);
	display: inline-block;
	margin: 0;
	padding: 2mm;
	border-radius: 1mm;
	
	border: 0.3mm solid;
	background-color: ${colors.modalbackground};
	box-shadow: 0 0 5mm;

}
`;

const html = `
<div class = "modalfull" tie="display:style.display, color:style.color">
	<span class = "modalframe" tieinner>
	</span>
</div>

`;





function modalfunc()
{
	var at = 
	{
		attributes:
		{
			get show()
			{
				return at.display == "block";
			}, 
			set show(v)
			{
				if(v==1)
				{
					at.display= "block";
				}
				else
				{
					at.display="none";
				}
			},
			get color()
			{
				return at.color;
			},
			set color(v)
			{
				at.color= colors[v];
			}
		},
		display: "block", 
		color: colors.info
	};
	return at;
}
modalfunc.css = css;
modalfunc.html = html;


$.comp("modal", modalfunc);

