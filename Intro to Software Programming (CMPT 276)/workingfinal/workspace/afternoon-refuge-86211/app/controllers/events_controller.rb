class EventsController < InheritedResources::Base
      before_action :authenticate_user!

      def index 
      @events= Event.all
       @events_by_date = Event.all.group_by {|i| i.date}
       @date = params[:date] ? Date.parse(params[:date]) :Date.today
    end


  private

    def event_params
      params.require(:event).permit(:event_name, :desription, :date, :location,:time)
    end
end
  
