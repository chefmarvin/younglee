import { Config } from '../config/config.type';
export default class Frame {
    config: Config;
    screen: any;
    mainBox: any;
    listtable: any;
    infoBox: any;
    constructor(config: Config);
    init(): void;
    screenWillMount(): void;
    render(): void;
}
