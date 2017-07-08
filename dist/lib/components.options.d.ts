import { Config } from '../config/config.type';
export declare function mainBoxOpt(screen: any, config: Config): any;
export declare function menuBarOpt(screen: any, config: Config): any;
export declare function infoBoxOpt(screen: any, config: Config): {
    parent: any;
    top: number;
    left: number;
    right: number;
    bottom: number;
    border: string;
    align: string;
    tags: boolean;
    keys: boolean;
    width: string;
    height: string;
    padding: {
        left: number;
    };
    content: string;
    style: {
        fg: string;
        bold: boolean;
        border: {
            bold: boolean;
            fg: string;
        };
    };
};
