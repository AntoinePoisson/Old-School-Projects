export const dataInitialState = {
    Data: [],
    Id: -1,
    Login: false,
    Token: "",
    TokenServices: [],
    About: [],
}


const dataReducer = (state, action) => {
    switch (action.type) {
        case "CLEAR_DATASTATE": {
            return { ...dataInitialState };
        }
        case "SET_TOKEN": {
            const { Token } = action;
            return { ...state, Token };
        }
        case "SET_TOKEN_SERVICES": {
            const { TokenServices } = action;
            return { ...state, TokenServices };
        }
        case "SET_ABOUT_JSON": {
            const { About } = action;
            return { ...state, About };
        }
        case "SET_RELOAD": {
            return { ...state };
        }
        case "SET_DATA": {
            const { About, Token, TokenServices } = action;
            return { ...state, About, Token, TokenServices  };
        }
        default:
            return state;
    };
};

export default dataReducer;