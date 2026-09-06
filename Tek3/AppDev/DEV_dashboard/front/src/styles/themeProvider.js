import { createMuiTheme } from '@material-ui/core/styles';


const mainTheme = createMuiTheme({
    palette: {
        background: {
            default: '#fafafa',
        },
        primary: {
            light: '#757ce8',
            main: '#3f51b5',
            dark: '#002884',
            contrastText: '#fff'
        },
        secondary: {
            light: '#ff7961',
            main: '#f44336',
            dark: '#ba000d',
            contrastText: '#000'
        }
    }
   }
);

export default mainTheme;